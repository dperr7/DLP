#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>


typedef union {
	
	/* access rtype with: instruction.rtype.(opcode|rd|funct3|rs1|rs2|funct7) */
	struct {
		char* op;
		int rd;
		int rs1;
		int rs2;
		char* label;
		int position;
	} rtype;
	
	/* access itype with: instruction.itype.(oppcode|rs|rt|imm) */
	struct {
		char* op;
		int rd;
		int rs1;
		int imm;
		char* label;
		int position;
	} itype;
	
	/* access jtype with: instruction.jtype.(opcode|addr) */
	struct {
		char* op;
		int rd;
		int imm;
		char* label;
		int position;
	} jtype;

} Instruction;

void readFile (char* filename, int n);
char* lowerCase(char* name);
int stringEquals(char *s1, char *s2);
int isRtype(char* ins);
int isItype(char* ins);
int isJtype(char* ins);
void writeFile (Instruction ins);

int stringEquals(char *s1, char *s2){

  char* string1 = (void *) s1;
  char* string2 = (void *) s2;
  //strcmp returns 0 if the strings are equal, 1 if not
  //although 0 is false and 1 is true in C
  if (!strcmp(string1, string2)) {
	return 1; //the strings are equal
  }

  return 0; //the strings are different
}

int isLabel(char* label) {

	if (isRtype(label)) {
		return 0;

	} else if (isItype(label)) {
		return 0;

	} else if (isJtype(label)) {
		return 0;

	}

	return 1;

}

char* lowerCase(char* name) {

	for(int i = 0; name[i]; i++){
		name[i] = tolower(name[i]);
	}

	return name;
}

int isRtype(char* ins) {

	if (stringEquals(ins, "sll")) {
		return 1;

	} else if (stringEquals(ins, "srl")) {
		return 1;

	} else if (stringEquals(ins, "sra")) {
		return 1;

	} else if (stringEquals(ins, "sltu")) {
		return 1;

	} else if (stringEquals(ins, "sgtu")) {
		return 1;

	} else if (stringEquals(ins, "sleu")) {
		return 1;

	} else if (stringEquals(ins, "sgeu")) {
		return 1;

	} else if (stringEquals(ins, "add")) {
		return 1;

	} else if (stringEquals(ins, "addu")) {
		return 1;

	} else if (stringEquals(ins, "sub")) {
		return 1;

	} else if (stringEquals(ins, "subu")) {
		return 1;

	} else if (stringEquals(ins, "and")) {
		return 1;

	} else if (stringEquals(ins, "or")) {
		return 1;

	} else if (stringEquals(ins, "xor")) {
		return 1;
		
	} else if (stringEquals(ins, "seq")) {
		return 1;
		
	} else if (stringEquals(ins, "sne")) {
		return 1;
		
	} else if (stringEquals(ins, "slt")) {
		return 1;
		
	} else if (stringEquals(ins, "sgt")) {
		return 1;
		
	} else if (stringEquals(ins, "sle")) {
		return 1;
		
	} else if (stringEquals(ins, "sge")) {
		return 1;
		
	}

	return 0;
}

int isItype(char* ins) {

	if (stringEquals(ins, "beqz")) {
		return 1;

	} else if (stringEquals(ins, "bnez")) {
		return 1;

	} else if (stringEquals(ins, "addi")) {
		return 1;

	} else if (stringEquals(ins, "addui")) {
		return 1;

	} else if (stringEquals(ins, "subi")) {
		return 1;

	} else if (stringEquals(ins, "subui")) {
		return 1;

	} else if (stringEquals(ins, "andi")) {
		return 1;

	} else if (stringEquals(ins, "ori")) {
		return 1;

	} else if (stringEquals(ins, "xori")) {
		return 1;

	} else if (stringEquals(ins, "lhi")) {
		return 1;

	} else if (stringEquals(ins, "seqi")) {
		return 1;

	} else if (stringEquals(ins, "snei")) {
		return 1;

	} else if (stringEquals(ins, "slti")) {
		return 1;

	} else if (stringEquals(ins, "sgti")) {
		return 1;
		
	} else if (stringEquals(ins, "slei")) {
		return 1;
		
	} else if (stringEquals(ins, "sgei")) {
		return 1;
		
	} else if (stringEquals(ins, "lb")) {
		return 1;
		
	} else if (stringEquals(ins, "lh")) {
		return 1;
		
	} else if (stringEquals(ins, "lw")) {
		return 1;
		
	} else if (stringEquals(ins, "lbu")) {
		return 1;
		
	} else if (stringEquals(ins, "lhu")) {
		return 1;
		
	} else if (stringEquals(ins, "sb")) {
		return 1;
		
	} else if (stringEquals(ins, "sh")) {
		return 1;
		
	} else if (stringEquals(ins, "sw")) {
		return 1;
		
	} else if (stringEquals(ins, "sequi")) {
		return 1;
		
	} else if (stringEquals(ins, "sneui")) {
		return 1;
		
	} else if (stringEquals(ins, "sltui")) {
		return 1;
		
	} else if (stringEquals(ins, "sgtui")) {
		return 1;
		
	} else if (stringEquals(ins, "sleui")) {
		return 1;
		
	} else if (stringEquals(ins, "sgeui")) {
		return 1;
		
	} else if (stringEquals(ins, "slli")) {
		return 1;
		
	} else if (stringEquals(ins, "srli")) {
		return 1;
		
	} else if (stringEquals(ins, "srai")) {
		return 1;
		
	}

	return 0;

}

int isJtype (char* ins) {

	if (stringEquals(ins, "j")) {
		return 1;

	} else if (stringEquals(ins, "jal")) {
		return 1;

	} else if (stringEquals(ins, "jr")) {
		return 1;

	} else if (stringEquals(ins, "jalr")) {
		return 1;

	}

	return 0;
}

void writeFile (Instruction ins) {
	;
}

int numberOfIns(char* filename) {
	FILE* fp;
	int n=0;
	char ch;

	// Open the file in read ("r") mode
	fp = fopen(filename, "r");

	// If the constructor is null then the file couldn't be read
	if (fp == NULL)
		exit(EXIT_FAILURE);

	
	// Read lines from file until theres nothing else to read (size -1)
	while ((ch = fgetc(fp)) != EOF) {
		n = n + 1;
	}

	fclose(fp);

	return n;
}

void readFile (char* filename, int n) {
	
	//File constructor
	FILE * fp;
	// String that will contain a line, null at the beginning
	char * line = NULL;
	// Length of a line, 0 at the beginning
	size_t len = 0;
	// Size of what's being read
	ssize_t read;
	char* token;
	char* token2;
	char* colon;
	char* label;
	char* s;

	//Keep track of the position of a instruction in the program (equivalent to the PC)
	int pos=0;

	//list of labels, the position of the label in the array
	//is the number of the instruction
	//for example, to know the instruction of label start
	//just find the string start in the jump list and get it's index
	//with the index we can know the position of the instruction and calculate the jump
	char* jump[n];

	// Open the file in read ("r") mode
	fp = fopen(filename, "r");

	// If the constructor is null then the file couldn't be read
	if (fp == NULL)
		exit(EXIT_FAILURE);

	// Read lines from file until theres nothing else to read (size -1)
	while ((read = getline(&line, &len, fp)) != -1) {
		Instruction ins;
		// In "line" is the first token, in "token" there's a pointer to the next pointer
		token= strtok(line, " :,()");
		lowerCase(token);

		if (isLabel(token)) {
			//save the label
			label = malloc(sizeof(char)*strlen(token));
			strcpy(label, token);

			//read next token
			token = strtok(NULL, " :,()");
			lowerCase(token);
			
			if (isRtype(token)){
				
				pos = pos + 1;
				
				ins.rtype.label = malloc(sizeof(char)*strlen(label));
				strcpy(ins.rtype.label, label);

				ins.rtype.op = malloc(sizeof(char)*strlen(token));
				strcpy(ins.rtype.op, token);

				token = strtok(NULL, " :,()rR");
				ins.rtype.rd = (int)atoi(token);
				
				token = strtok(NULL, " :,()rR");
				ins.rtype.rs1 = (int)atoi(token);
				
				token = strtok(NULL, " :,()rR");
				ins.rtype.rs2 = (int)atoi(token);

				ins.rtype.position = pos;

				
			} else if (isItype(token)) {
				pos = pos + 1;
				ins.itype.position = pos;

			} else if (isJtype(token)) {
				pos = pos + 1;
				ins.jtype.position = pos;

			} else {
				fprintf(stderr, "Unvalid instruction\n");
			}

			jump[pos-1] = label;

		} else {

			label = ""; //there's no label

			if (isRtype(token)){

				ins.rtype.label = malloc(sizeof(char)*strlen(label));
				strcpy(ins.rtype.label, label);

				pos = pos + 1;

				ins.rtype.op = malloc(sizeof(char)*strlen(token));
				strcpy(ins.rtype.op, token);

				token = strtok(NULL, " :,()rR");
				ins.rtype.rd = (int)atoi(token);
				
				token = strtok(NULL, " :,()rR");
				ins.rtype.rs1 = (int)atoi(token);
				
				token = strtok(NULL, " :,()rR");
				ins.rtype.rs2 = (int)atoi(token);

				ins.rtype.position = pos;

			} else if (isItype(token)) {
				pos = pos + 1;

				ins.rtype.op = malloc(sizeof(char)*strlen(token));
				strcpy(ins.rtype.op, token);

				ins.itype.position = pos;

			} else if (isJtype(token)) {
				pos = pos + 1;

				ins.rtype.op = malloc(sizeof(char)*strlen(token));
				strcpy(ins.rtype.op, token);

				token = strtok(NULL, " :,()rR");
				//int j = getJump(token);

				ins.jtype.position = pos;

			} else {
				fprintf(stderr, "Unvalid instruction\n");
			}

			jump[pos-1] = "";
			
		}

		printf("The instruction label is\n");
		printf("%s\n", ins.rtype.label);
		printf("The instruction opcode is\n");
		printf("%s\n", ins.rtype.op);
		printf("The instruction rd is\n");
		printf("%d\n", ins.rtype.rd);
		printf("The instruction rs1 is\n");
		printf("%d\n", ins.rtype.rs1);
		printf("The instruction rs2 is\n");
		printf("%d\n", ins.rtype.rs2);

		//Free the memory!


	}

	// Close file
	fclose(fp);
	
	// If line contains something then free the space (we are not goint to use it anymore)
	if (line)
		free(line);
	
}



int main(int argc, char **argv) {
	int m;
	if (argc != 2) {
		printf("Error. You must enter the name of the input file.\n");
		return 1;
	}

	m = numberOfIns(argv[1]);
	readFile(argv[1], m);

	return 0;

}