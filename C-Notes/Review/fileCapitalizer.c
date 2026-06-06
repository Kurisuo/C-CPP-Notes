#include <fcntl.h>    // For open(), O_RDONLY, O_WRONLY, etc.
#include <unistd.h>   // For read(), write(), close()
#include <stdio.h>    // For perror(), fprintf()
#include <stdlib.h>   // For exit()
#include <ctype.h>    // For toupper()


/*
Objective:
 A program that takes two filenames (input file & output file) as command line args.
 --> Read Contents of Input File
 --> Convert all lowercase letters to uppercase
 --> Write transformed text to output file

 argc = 3 because of 1) name 2) input file 3) output file
*/

#define BUFFER_SIZE 1024
#define BAD_REQUEST 400

int handle_conversion(int argc, char* argv[]){ 

    char buff[BUFFER_SIZE];
    int bytes_total = 0;
    int bytes_read = 0;

    int fd_input = open(argv[1], O_RDONLY); //input file open for reading
    if(fd_input < 0){ 
        close(fd_input);
        return BAD_REQUEST;
    }

    do { 

        

    } while();


    int fd_output = open(argv[2], O_WRONLY| O_TRUNC, 0644);




    do { 
        write();



    } while(bytes_written < BUFFER_SIZE);

 

        bytes_read = read(fd, buff, 1);
        bytes_total += bytes_read;
        if(bytes_read < 0){return BAD_REQUEST;}
        


    

}




int main(int argc, char* argv[]){ 
    //argc: argument count - number of arguments passed by user
    //argv: argument vector - array of character pointers listing all arguments

    //if argc > 0: argv[0] to argv[argc - 1] will contain pointers to strings
    //argv[0] name of the program

    if(argc != 3){ 
        fprintf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    int err = handle_conversion(argc, argv);


    return err;
}