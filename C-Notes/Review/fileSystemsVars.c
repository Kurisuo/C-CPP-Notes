#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


open(path, flags, privacySerial); //Returns a File Descriptor | Returns -1 on Failure
read(fd, buf, count); //Returns -1 on Failure | Returns 0 on EOF | Returns Number of Bytes Read
write(fd, buf, count);//Returns -1 on Failure | Returns 0 on EOF | Returns Number of Bytes Written

// read() & write() must use a loop to process ALL bytes requested
//We advance our buffer pointer forward by result bytes and decrease remaining bytes counter by results
//We provide read() with the maximum number of bytes it should read

ssize_t res;
while(n > 0){ 

    res = write(fd, buf, 1);
    if (res < 0){ 
        error();
        break;
    }
    if(res == 0){
        break;
    }
    p += res; //increase pointer
    n -= res; //decrease byte count remaining

}


//STATIC: Restricted Local Scope; Persist for lifetime of program
//GLOBAL: Exist only during local scope execution