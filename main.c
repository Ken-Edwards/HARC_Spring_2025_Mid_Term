#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  NUM_STUDENTS  5
#define  RETURN_SUCCESS 0
#define  RETURN_FAIL 1

struct studentGrades {
  char first_name[15];      // in input file
  char last_name[15];       // in input file
  float homeworks[10];      // in input file
  float labs[4];            // in input file
  float quizes[2];          // in input file
  float mid_term;           // in input file
  float final;              // in input file
  float homework_average;   // derived value
  float lab_average;        // derived value
  float quiz_average;       // derived value
  float numeric_grade;      // derived value
  char Letter_grade;        // derived value
  };

struct studentGrades *StudentArray[NUM_STUDENTS];
struct studentGrades *(*p)[] = &StudentArray;  // an array of pointers to structs

/* Since we are defining the Student structure array and it pointer, and the array of
   pointers for the student array as globals, you need not pass or return these pointers */

/* Prototype for functions
 int read_student_data_file(FILE* fptr);
 int analyze_student_data(void);
 int print_student_data(FILE* fptr);
 */


int main()
{

  FILE* file_ptr;
  int check_valid;

/*  Code that can be used elsewhaere
    int i;
    float final_numeric_grade;

    for (i=0;i<NUM_STUDENTS;i++) {
      StudentArray[i] = malloc(sizeof(struct studentGrades));
      }

*/

       file_ptr = fopen("input_data.txt", "r");
       if (file_ptr == NULL) {
         return RETURN_FAIL;
         }
        else {
         check_valid = read_student_data_file(file_ptr);
         if (check_valid  == RETURN_FAIL) {
           fclose(file_ptr);
           return RETURN_FAIL;
           }
          else {
           fclose(file_ptr);
           check_valid = analyze_student_data();
           if (check_valid  == RETURN_FAIL) {
             return RETURN_FAIL;
             }
            else {
             file_ptr = fopen("student_report.txt", "w");
             if (file_ptr == NULL) {
               return RETURN_FAIL;
               }
              else {
               check_valid =  print_student_data(file_ptr);
               if (check_valid  == RETURN_FAIL) {
                 return RETURN_FAIL;
                 }
               }
             }
           }
         }


    /* pointer p is a pointer to an array of structure pointers,
       each structure pointer in the array points to the a single
       student structure

       Below is the method to access a data element for a single
       student, in this case the first student, index 0


    strcpy((*p)[0]->first_name,"John");


    final_numeric_grade = (*p)[0]->numeric_grade;
 */

    return 0;
}
