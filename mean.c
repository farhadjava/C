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
void exit();

struct book_info{
     int id;
     char name[10];
     char author[10];
     int quantity[10];
     int rack[10];
};
 
struct book_info a;

FILE *file, *file2;

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
  printf("\t\t   6.exit\n");

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
             exit (int __status);
       }
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
  scanf("%s",a.quantity);
      
  printf("The Rack No :");
  scanf("%s",a.rack);

  fseek(file,0,SEEK_END);
  fwrite(&a,sizeof(a), 1, file);
  fclose(file);

  printf("\n\n\t\t AddBook sucessfully Complete!");
  fflush(stdin);
  getchar();
  mainMenu();
}

void viewbook(){
     int count = 0;
     printf("\n\n\t\t ********** ViewBook List ***********\n\n");
     printf("\tID\tName\tAuthor\tQuantity\tRack\n\n");
     file = fopen("books.bat","rb");
     while(fread(&a,sizeof(a),1,file)==1){
         printf("\t%d",a.id);
         printf("\t%s",a.name);
         printf("\t%s",a.author);
         printf("\t%s",a.quantity);
         printf("\t%s",a.rack);
        
         count = count + *(a.quantity); 

  }
  
  printf("\n\t\t Have a total books %d",count);
  printf("\n\n\t\tpress any key...");
  fflush(stdin);
  getchar();

  mainMenu();
}

void searchbook(){
     int d, count = 0;
     printf("\n\n\t\t ********** search Book ********\n");
     printf("\n\t\t searching ......\n\n");
     file = fopen("books.dat","rb");
     
     printf("\n\t\t Enter ID: ");
     scanf("%d",&d);
     while(fread(&a,sizeof(a),1,file)==1){
          if(d == a.id){
              printf("\n\n\t\t Book is Found..! \n");
              printf("\t\t ID: %d",a.id);
              printf("\n\t\t Name: %s",a.name);
              printf("\n\t\t Author: %s",a.author);
              printf("\n\t\t quantity: %s",a.quantity);
              printf("\n\t\t Rack: %s",a.rack);
              
              count = 1;
          }
     
     }
     if(count == 0){
         printf("\n\n Book is not Found  !");
     }
     
     printf("\n\n\t\t press any key......");
     fflush(stdin);
     getchar();
     
     mainMenu();
     
}

void editbook(){
     int d,count=0;
     printf("\n\n\t\t ********* edit book ******** \n\n");
     file = fopen("book.dat","rb+");
     
     printf("\n\n\t Enter your ID:\n");
     scanf("%d",&d);
     
     while(fread(&a,sizeof(a),1,file)==1){
         if(d == a.id){
           printf("\n\t\t Book is aviabile\n");
           printf("\n\n ID : %d",a.id);
           printf("\n\t\t Enter New Name : ");
           scanf("%s",a.name);
           printf("\n\t\t Enter New Author : ");
           scanf("%s",a.author);
           printf("\n\t\t Enter New Quantity : ");
           scanf("%d",&a.quantity);
           printf("\n\t\t Enter New Rack : ");
           scanf("%d",&a.rack);
           
           fseek(file,ftell(file) - sizeof(a),0);
           
           fwrite(&a,sizeof(a),1,file);
           fclose(file);
           count = 1;
         
         }
     
     }
     if(count == 0){
       printf("\n\t\t Book is not found :");
     
     }
     printf("press any key.....");
     fflush(stdin);
     getchar();
     mainMenu();
}

void deletebook(){
   int d,count = 0;
   printf("\n\n\t\t********* Delete Book ********");
   printf("\n\n\t\t Enter id for delete book");
   scanf("%d",&d);
   
   file = fopen("book.dat","rb+");
   rewind(file);
   while(fread(&a,sizeof(a),1,file)==1){
        
        if(d == a.id){
          printf("\n\t\t The books is availble..");
          printf("\n\t\t Book name is:%s",a.name);
          printf("\n\t\t Rack No:%d",a.rack);
          
          count = 1;     
        }
    }
    
    if(count == 0){
      printf("\n\t\t This book is not availble");
    }
    else{
        file2 = fopen("text.dat","wb");
        
        rewind(file);
        while(fread(&a,sizeof(a),1,file)==1){
            
            if(d != a.id){
            
              fseek(file2,ftell(file2)-sizeof(a),0);
              fwrite(&a,sizeof(a),1,file);
            }
            
            fclose(file);
            fclose(file2);
            
            remove("books.dat");
            rename("text.dat","books.dat");
            file= fopen("books,dat","rb");
            
            fclose(file);
        }
    }
    printf("\n\t\t press any key....!");
    fflush(stdin);
    getchar();
    
    mainMenu();
         
}

void exit ( int status){

     int i;

     printf("\n\n\t\t This is simple Library Project \n");
     printf("\n\n\n \t\t\t Thank you \n\n");
     printf("\n\t\t\t Wait....");
     
     for(i = 1; i < 1e8; i++){
     
     }
     
     exit(0);
}

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
