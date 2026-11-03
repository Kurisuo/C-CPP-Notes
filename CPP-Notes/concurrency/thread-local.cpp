//Thread-local Variables

//Each thread is given a local variable in which it can use it to remember information such as a boolean flag 


thread_local std::size_t my_slot = 0;

//If thread_A changes my_slot to 1, thread_B's will remain unchanged
//--> thread-local pointers can point to a node other threads access

