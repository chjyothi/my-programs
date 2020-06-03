
#include <stdio.h>
#include <stdlib.h> // For exit() function
void file_creation();
void reading_file();
int main() {
    
    
    char str1;
     printf("---------function for creating file and adding content-----------");
    file_creation();
    printf("---------function for reading from file-----------");
    reading_file();
      return 0;
}
   void file_creation()
    {
       FILE *fptr;
       int n,i;
       char sentence[1000];
         printf(" Input the number of lines to be written : ");
	scanf("%d", &n);
        //opening file in writing file
    fptr = fopen("C:/Users/chjyo/Desktop/sravya/file.txt", "w");

    // exiting program 
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }
   
             
    printf("Enter a sentence:\n");
    for(i=0;i<n+1;i++)
    {
    fgets(sentence, sizeof(sentence), stdin);
    fprintf(fptr,sentence);
    }
    fclose(fptr);
    }
    
    
    
    
   void reading_file()
   {
       FILE *fptr;
       int n,i;
       char str1;
  //opening and reading from the file
    fptr = fopen("C:/Users/chjyo/Desktop/sravya/file.txt", "r");
    printf("---------Reading from the file-----------");
    str1 = fgetc(fptr);
	while (str1 != EOF)
		{
			printf ("%c", str1);
			str1 = fgetc(fptr);
		}
    
    
    fclose(fptr);
   }

  