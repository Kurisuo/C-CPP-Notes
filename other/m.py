import sys
try:
    import numpy as np  # type: ignore
except Exception:
    sys.exit("numpy is required to run this script. Please install it (e.g. pip install numpy)")
try:
    import matplotlib as mpl  # type: ignore
    mpl.use("Agg")
    import matplotlib.pyplot as plt  # type: ignore
except Exception:
    sys.exit("matplotlib is required to run this script. Please install it (e.g. pip install matplotlib)")
try:
    from matplotlib.patches import Arc, Polygon, FancyArrowPatch  # type: ignore
except Exception:
    sys.exit("matplotlib.patches is required to run this script. Please install matplotlib properly")

plt.rcParams.update({
    "font.family": "serif",
    "mathtext.fontset": "dejavuserif",
    "font.size": 12,
    "axes.linewidth": 1.0,
    "savefig.dpi": 200,
})

# ------------------------------------------------------------------
# FIGURE 2: Reflection  (theta_i vs theta_r)
# ------------------------------------------------------------------
ti = np.array([0, 30, 45, 60, 75], dtype=float)
tr = np.array([0, 30, 45, 60, 75], dtype=float)

fig, ax = plt.subplots(figsize=(6.5, 4.5))
xl = np.linspace(0, 80, 50)
ax.plot(xl, 1.0 * xl, color="#1f5fa8", lw=2,
        label=r"Best fit: $\theta_r = 1.00\,\theta_i + 0.00$" + "\n" + r"$R^2 = 1.000$")
ax.scatter(ti, tr, s=60, color="#c0392b", zorder=5, edgecolor="black", linewidth=0.6,
           label="Measured data")
ax.set_xlabel(r"Angle of Incidence  $\theta_i$  (degrees)")
ax.set_ylabel(r"Angle of Reflection  $\theta_r$  (degrees)")
ax.set_title("Reflection Through Mirror")
ax.set_xlim(0, 80)
ax.set_ylim(0, 80)
ax.set_xticks(np.arange(0, 81, 15))
ax.set_yticks(np.arange(0, 81, 15))
ax.grid(True, ls=":", color="#bbbbbb")
ax.legend(loc="upper left", frameon=True, fontsize=11)
fig.tight_layout()
fig.savefig("reflection_plot.png")
plt.close(fig)

# ------------------------------------------------------------------
# FIGURE 3: Refraction  (sin theta1 vs sin theta2)  -- Snell's Law
# ------------------------------------------------------------------
s1 = np.array([0.000, 0.500, 0.707, 0.866, 0.966])
s2 = np.array([0.000, 0.375, 0.530, 0.643, 0.719])
slope = 0.738  # student's reported best-fit slope (line through origin)

fig, ax = plt.subplots(figsize=(6.5, 4.5))
xl = np.linspace(0, 1.0, 50)
ax.plot(xl, slope * xl, color="#1f5fa8", lw=2,
        label=(r"Best fit: $\sin\theta_2 = 0.738\,\sin\theta_1$" + "\n"
               + r"$n_{water} = 1/0.738 = 1.36$" + "\n" + r"$R^2 = 0.999$"))
ax.scatter(s1, s2, s=60, color="#c0392b", zorder=5, edgecolor="black", linewidth=0.6,
           label="Measured data")
ax.set_xlabel(r"$\sin\theta_1$  (incident, in air)")
ax.set_ylabel(r"$\sin\theta_2$  (refracted, in water)")
ax.set_title("Refraction Through Water")
ax.set_xlim(0, 1.0)
ax.set_ylim(0, 0.8)
ax.grid(True, ls=":", color="#bbbbbb")
ax.legend(loc="upper left", frameon=True, fontsize=11)
fig.tight_layout()
fig.savefig("refraction_plot.png")
plt.close(fig)

# ------------------------------------------------------------------
# FIGURE 1: Ray diagram (Reflection | Refraction | TIR)
# ------------------------------------------------------------------
def arrow(ax, x0, y0, x1, y1, color="#c0392b", lw=2.2):
    ax.add_patch(FancyArrowPatch((x0, y0), (x1, y1),
                 arrowstyle="-|>", mutation_scale=16, color=color, lw=lw,
                 shrinkA=0, shrinkB=0, zorder=6))

def normal(ax, top=1.0, bot=0.0):
    ax.plot([0, 0], [bot, top], ls=(0, (6, 4)), color="#444444", lw=1.4, zorder=2)

fig, axes = plt.subplots(1, 3, figsize=(11, 3.7))
for ax in axes:
    ax.set_xlim(-1.05, 1.05)
    ax.set_ylim(-1.05, 1.05)
    ax.set_aspect("equal")
    ax.axis("off")

# ---- Panel 1: Reflection ----
ax = axes[0]
ax.axhline(0, color="black", lw=2)
# mirror hatch
for hx in np.linspace(-0.95, 0.85, 11):
    ax.plot([hx, hx + 0.12], [0, -0.14], color="black", lw=0.9)
normal(ax, top=1.0, bot=0.0)
# incident from upper-left to origin (40 deg from normal)
ang = np.deg2rad(40)
ix, iy = -np.sin(ang), np.cos(ang)
arrow(ax, 0.95 * ix, 0.95 * iy, 0, 0)
# reflected from origin to upper-right
rx, ry = np.sin(ang), np.cos(ang)
arrow(ax, 0, 0, 0.95 * rx, 0.95 * ry)
# angle arcs
ax.add_patch(Arc((0, 0), 0.5, 0.5, angle=0, theta1=90, theta2=90 + 40, color="#1f5fa8", lw=1.6))
ax.add_patch(Arc((0, 0), 0.5, 0.5, angle=0, theta1=50, theta2=90, color="#1f5fa8", lw=1.6))
ax.text(-0.20, 0.42, r"$\theta_i$", color="#1f5fa8", fontsize=13)
ax.text(0.12, 0.42, r"$\theta_r$", color="#1f5fa8", fontsize=13)
ax.text(0, -0.32, "Mirror", ha="center", fontsize=10)
ax.text(0.03, 0.98, "Normal", ha="left", va="top", fontsize=9, color="#444444")
ax.set_title(r"Reflection: $\theta_i = \theta_r$", fontsize=12)

# ---- Panel 2: Refraction (air -> water) ----
ax = axes[1]
ax.add_patch(Polygon([(-1.05, -1.05), (1.05, -1.05), (1.05, 0), (-1.05, 0)],
                     closed=True, facecolor="#cfe8f5", edgecolor="none", zorder=0))
ax.axhline(0, color="black", lw=2)
normal(ax, top=1.0, bot=-1.0)
# incident in air (upper-left), theta1 = 40 deg
a1 = np.deg2rad(40)
arrow(ax, -0.95 * np.sin(a1), 0.95 * np.cos(a1), 0, 0)
# refracted in water (lower-right), theta2 = 28 deg (bends toward normal)
a2 = np.deg2rad(28)
arrow(ax, 0, 0, 0.95 * np.sin(a2), -0.95 * np.cos(a2))
# faint partial reflection
ax.add_patch(FancyArrowPatch((0, 0), (0.8 * np.sin(a1), 0.8 * np.cos(a1)),
             arrowstyle="-|>", mutation_scale=11, color="#c0392b", lw=1.0,
             alpha=0.35, shrinkA=0, shrinkB=0))
ax.add_patch(Arc((0, 0), 0.5, 0.5, angle=0, theta1=90, theta2=90 + 40, color="#1f5fa8", lw=1.6))
ax.add_patch(Arc((0, 0), 0.45, 0.45, angle=0, theta1=270, theta2=270 + 28, color="#16734f", lw=1.6))
ax.text(-0.22, 0.42, r"$\theta_1$", color="#1f5fa8", fontsize=13)
ax.text(0.10, -0.40, r"$\theta_2$", color="#16734f", fontsize=13)
ax.text(-1.0, 0.80, r"Air  $n_1 = 1.00$", fontsize=9)
ax.text(-1.0, -0.92, r"Water  $n_2 = 1.33$", fontsize=9)
ax.set_title(r"Refraction: $n_1\sin\theta_1 = n_2\sin\theta_2$", fontsize=12)

# ---- Panel 3: TIR (water -> air, beyond critical angle) ----
ax = axes[2]
ax.add_patch(Polygon([(-1.05, -1.05), (1.05, -1.05), (1.05, 0), (-1.05, 0)],
                     closed=True, facecolor="#cfe8f5", edgecolor="none", zorder=0))
ax.axhline(0, color="black", lw=2)
normal(ax, top=0.55, bot=-1.0)
# incident in water from lower-left, theta = 58 deg (> theta_c)
ac = np.deg2rad(58)
arrow(ax, -0.95 * np.sin(ac), -0.95 * np.cos(ac), 0, 0)
# totally reflected back down to lower-right
arrow(ax, 0, 0, 0.95 * np.sin(ac), -0.95 * np.cos(ac))
# grazing (would-be) ray faint along surface
ax.add_patch(FancyArrowPatch((0, 0), (0.9, 0.0), arrowstyle="-|>", mutation_scale=10,
             color="#999999", lw=1.0, alpha=0.5, shrinkA=0, shrinkB=0, ls=(0, (3, 3))))
ax.add_patch(Arc((0, 0), 0.5, 0.5, angle=0, theta1=270, theta2=270 + 58, color="#16734f", lw=1.6))
ax.add_patch(Arc((0, 0), 0.42, 0.42, angle=0, theta1=270 - 58, theta2=270, color="#16734f", lw=1.6))
ax.text(0.16, -0.34, r"$\theta$", color="#16734f", fontsize=13)
ax.text(-0.42, -0.34, r"$\theta$", color="#16734f", fontsize=13)
ax.text(-1.0, 0.78, r"Air  $n = 1.00$", fontsize=9)
ax.text(-1.0, -0.92, r"Water  $n = 1.33$", fontsize=9)
ax.text(0.42, 0.07, "no escape", fontsize=8, color="#777777")
ax.set_title(r"TIR: $\theta \geq \theta_c$", fontsize=12)

fig.tight_layout()
fig.savefig("ray_diagram.png")
plt.close(fig)

print("Saved reflection_plot.png, refraction_plot.png, ray_diagram.png")
