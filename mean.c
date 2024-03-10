#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void password();
void heading();
void mainMenu();
void addbook();
void viewbook();
void searchbook();
void editbook();
void deletebook();
void Helpbook();
//void exit();

struct book_info{
     int id;
     char name[10];
     char author[10];
     int quantity;
     int rack;
};
 
struct book_info a;

FILE *file;

int d = 1;

int main(){
    password();
}
// we are take a working mainMenu().
void mainMenu()
{
  int n;
  printf("\n\n\t\t @@@@@@@@@@ Main Manu @@@@@@@@\n");

  printf("\n\t\t  1.add book\n");
  printf("\t\t   2.view book\n");
  printf("\t\t   3.search book\n");
  printf("\t\t   4.edit book\n");
  printf("\t\t   5.delete book\n");
  printf("\t\t   6.Help\n");
  //printf("\t\t   7.exit\n");

  printf("\t\t^^^^^^^^^^^^^^^^^^^^^^^\n");
  printf("\t\tEnter your choice:");
  scanf("%d",&n);
  if(n==1){
    
     addbook();
  }

   else if(n==2){
       viewbook();
   }
    else if(n==3){
        searchbook();
    }
     else if(n==4){ 
         editbook();
     }
      else if(n==5){ 
          deletebook();
      }
       else if(n==6){ 
           Helpbook();
        }
        //else if(n==7){ 
             //exit();
         //}
       else{
          printf("\n\n \t\t Your choice is Wrong! \n \t\t Let's Try agani...");
          fflush(stdin);
          getchar();

          mainMenu();
         }

}

void addbook(){
     int d,count = 0;

     printf("\n\n\t\t ********AddBook*******\n");
     file = fopen("book.bat","ab+");

     printf("\n\n Enter the ID :\n");
     fflush(stdin);
     scanf("%d",&d);

     rewind(file);
     while(fread(&a, sizeof(a),1,file)==1){
          if(d == a.id){
            printf("The book already have it..! \n");
            count = 1;
      
     }
  
  }
  if(count == 1){
    fflush(stdin);
    getchar();
    mainMenu();
  }
  a.id = d;

  printf("Enter Name :");
  fflush(stdin);
  scanf("%s",a.name);

  printf("Enter Author :");
  fflush(stdin);
  scanf("%s",a.author);

  printf("The Quantity :");
  scanf("%d",a.quantity);
      
  printf("The Rack No :");
  scanf("%d",a.rack);

  fseek(file,0,SEEK_END);
  fwrite(&a,sizeof(a), 1, file);
  fclose(file);

  printf("\n\n\t\t AddBook sucessfully Complete!");
  fflush(stdin);
  getchar();
  mainMenu();
}

void viewbook(){
     printf("VIEW book is ready...!\n");
}

void editbook(){
     printf("Can you Edit the book...!");
}
void searchbook(){
     printf("Now you can Searchbook...!");
}

void Helpbook(){
     printf("From now Any book you can want to help...!");
}
void deletebook(){
     printf("Now as your wish can be Deletebook...!");
}

//void exit(){
     //printf("Open Exit...!");
//}

// we are working take heading file.

void heading(){ // we are make to heading file going to work.

     printf("\n\n \t\t ******** Library mangement system ******* \n");
     //fflush(stdin);
     //getchar(); 
}

// we are working password

void password(){ //at first we are take a password funation from call by main funation.
     heading();  // we are take heading file from call by password.

     char pwd1[10]=("admin");
     char pwd2[10];

     printf(" \n \t\t Enter Password: ");
     scanf("%s",pwd2);
     
     if(strcmp(pwd1,pwd2) == 0)
     {
        printf("\n\n \t\t Match Password!\n");
        printf("\n \t\t press the secret Number...");
     }
     else{
         if(d == 3)
         {
            exit(0);
         }
         
         printf("\n\n \t\t Wrong Password! %d to 3 time \n",d);
         printf("\n\n \t\t  Try again.....");
         d++;

         fflush(stdin);  // we are take a from user input standerinput.
         getchar();

         password();
     }

     fflush(stdin);
     getchar();

     mainMenu();
}
