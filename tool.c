/*
 * Yusuf Abdi
 *
 */


#include <stdio.h> // Used for input/output (including file operations)
#include <stdlib.h>
#include <string.h>

//maximum number of characters in C String
#define BUF_SIZE 255

//Instruction structure
struct Instruction {
    
    char name[4]; //first 3 characters only
    int totalInstructions;
    int totalCycles;
};

//get instruction, return index in table
int getInstructionIndex(struct Instruction instructionTable[],
    int instructionTableLength,
    const char* instructionName);
/*
 * main function to start C application
 * arguments:
 * argc: number of arguments
 * argv[0]: execute file name
 * argv[1]: input file name
 * */

int main(int argc, char** argv) {

    // FILE is a typedef in stdio.h
    // FILE is actually a very simple structure, representing
    // a 'handle' to a file on your system.
    // In practice, this is just an 'integer' value.
    FILE* myFile;

    char name[4];//3 characters to test
    int i, j; //loop control variable

    //total instructions 
    int totalInstructions = 0;

    //total cycles
    int totalCycles = 0;

    int index; //index of instruction in array

    //Instruction structure
    struct Instruction instructionTable[9];
    int instructionTableLength = 9;

    //set up table
    strcpy(instructionTable[0].name, "ADD");
    instructionTable[0].totalInstructions = 1;
    instructionTable[0].totalCycles = 1;

    strcpy(instructionTable[1].name, "SUB");
    instructionTable[1].totalInstructions = 1;
    instructionTable[1].totalCycles = 1;

    strcpy(instructionTable[2].name, "MUL");
    instructionTable[2].totalInstructions = 1;
    instructionTable[2].totalCycles = 2;

    strcpy(instructionTable[3].name, "DIV");
    instructionTable[3].totalInstructions = 1;
    instructionTable[3].totalCycles = 4;

    strcpy(instructionTable[4].name, "MOV");
    instructionTable[4].totalInstructions = 1;
    instructionTable[4].totalCycles = 1;

    strcpy(instructionTable[5].name, "LEA");
    instructionTable[5].totalInstructions = 1;
    instructionTable[5].totalCycles = 1;

    strcpy(instructionTable[6].name, "PUS"); //push
    instructionTable[6].totalInstructions = 1;
    instructionTable[6].totalCycles = 1;

    strcpy(instructionTable[7].name, "POP");
    instructionTable[7].totalInstructions = 1;
    instructionTable[7].totalCycles = 1;

    strcpy(instructionTable[8].name, "RET");
    instructionTable[8].totalInstructions = 1;
    instructionTable[8].totalCycles = 1;


    //validate arguments
    if (argc != 2)
    {
        printf("Invalid input. Usage: %s <input file name>\n", argv[0]);
        return 1;
    }

    // open file in reading mode
    myFile = fopen(argv[1], "r");

    // check if file can be opened
    if (NULL == myFile) {
        fprintf(stderr, "%s not found\n", argv[1]);
        return 1;;
    }

    // assume each line in file can
    // be 'BUF_SIZE' characters at the most.
    char buffer[BUF_SIZE];

    //read line of line until end of file
    while (fgets(buffer, BUF_SIZE, myFile) != NULL) {

        //process line
        i = 0;

        //ignore spaces
        while (buffer[i] == ' ' || buffer[i] == '\t' || buffer[i] == '\n')
        {
            i++;
        }

        j = 0;
        while (i < strlen(buffer) && j < 3)
        {            
            if (buffer[i] >= 'a' && buffer[i] <= 'z')
            {
                name[j++] = (char)(buffer[i] - 32);//convert to upper case
            }
            else
            {
                name[j++] = buffer[i];
            }
            
            i++;
        }
        name[j] = '\0';

        //IMUL is equivalent to MUL
        if (strcmp(name, "IMU") == 0 && buffer[i] == 'L')
        {
            strcpy(name, "MUL");
        }
        //IDIV  is equivalent to DIV
        if (strcmp(name, "IDI") == 0 && buffer[i] == 'V')
        {
            strcpy(name, "DIV");
        }

        //get index by instruction name
        index = getInstructionIndex(instructionTable, instructionTableLength,
            name);

        if (index != -1)
        {
            //total instructions 
            totalInstructions += instructionTable[index].totalInstructions;

            //total cycles
            totalCycles += instructionTable[index].totalCycles;
        }
    }
    // Finally, we will close our file
    // Now our file is unavailable to be read from.
    //Generally, it is safe
    fclose(myFile);

    //print result
    
    printf("Total instructions: %d\n", totalInstructions);
    printf("Total cycles: %d\n", totalCycles);
   
    return 0;    
}

//get instruction, return index in table
int getInstructionIndex(struct Instruction instructionTable[],
    int instructionTableLength,
    const char* instructionName){

    int i;

    //loop the table and find
    for (i = 0; i < instructionTableLength; i++)
    {
        if (strcmp(instructionTable[i].name, instructionName) == 0)
        {
            return i;
        }
    }

    return -1;//not found

} 
