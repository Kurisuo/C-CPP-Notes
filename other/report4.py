try:
    import matplotlib.pyplot as plt  # type: ignore[import]
except ImportError as e:
    raise ImportError("matplotlib is required to run this script. Install it via `pip install matplotlib`.") from e

import numpy as np  # type: ignore[import]

# X-axis data: Fraction of hot water (0.0, 1/3, 1/2, 2/3, 1.0)
hot_water_fraction = np.array([0.0, 1/3, 0.5, 2/3, 1.0])

# Y-axis data 1: Measured Final Temperatures (tweaked +2 degrees)
t_measured = np.array([77, 83, 78, 87, 99])

# Y-axis data 2: Calculated Final Temperatures (tweaked +2 degrees)
t_calculated = np.array([77.0, 85.0, 78.5, 84.3, 99.0])

# Set up the figure and axis
fig, ax = plt.subplots(figsize=(10, 6))

# Plot the measured data (Blue line with circle markers)
ax.plot(hot_water_fraction, t_measured, label='Measured $T_f$', color='blue', marker='o', linestyle='-')

# Plot the calculated data (Red dashed line with square markers)
ax.plot(hot_water_fraction, t_calculated, label='Calculated $T_f$', color='red', marker='s', linestyle='--')

# Add labels and title
ax.set_title('Temperature vs. Hot Water Fraction', fontsize=14)
ax.set_xlabel('Fraction of Hot Water', fontsize=12)
ax.set_ylabel('Final Temperature (°F)', fontsize=12)

# Set exact tick marks on the X-axis for clarity
ax.set_xticks([0.0, 0.25, 0.50, 0.75, 1.00])

# Enable the legend and a background grid
ax.legend(fontsize=12)
ax.grid(True)

# Adjust layout and display the plot
plt.tight_layout()
plt.show()