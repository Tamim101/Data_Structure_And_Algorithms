// #include <stdio.h>
// void go_south_east(int *lat, int *lon)
// {
//  *lat = *lat - 1;
//  *lon = *lon + 1;
// }
// int main()
// {
//  int latitude = 2;
//  int longitude = -64;
//  go_south_east(&latitude, &longitude);
//  printf("Avast! Now at: [%i, %i]\n", latitude, longitude);
//  return 0;
// }

// #include<stdio.h>

// void fortune_cookie(char msg[])
// {
//  printf("Message reads: %s\n", msg);
// }
// char quote[] = "Cookies make you fat";

// fortune_cookie(quote);

// #include <stdio.h>
// int main()
// {
//  int contestants[] = {1, 2, 3};
//  int choice = contestants[0];  // Store the value, not pointer
//  contestants[0] = 2;
//  contestants[1] = contestants[2];
//  contestants[2] = choice;
//  printf("I'm going to pick contestant number %i\n", contestants[0]);
//  return 0;
// }


// #include <stdio.h>
//  char main()
// {
// char buffer[100];
// printf("Enter your name: ");
// fgets(buffer, 100, stdin);
// printf("You entered: %s", buffer);

// return 0;
// }



// #include<stdio.h>
// int main()
// {
//     char masked_raider[] = "Tamim khan is here";
//     char *Tamim = masked_raider;
//     printf("masked raider is %s,Tamim is %s\n" ,masked_raider,Tamim);
//     masked_raider[0] = 'H';
//     masked_raider[1] = 'E';
//     masked_raider[2] = 'L';
//     masked_raider[3] = 'L';
//     masked_raider[4] = 'O';
//     printf("Mask rider is %s,Tamim is %s",masked_raider,Tamim);
//     return 0;
// }
// #include<stdio.h>
// char main()
// {
//     char Tamim[100];
//     printf("Enter favorite food: ");
//     fgets(Tamim,sizeof(Tamim),stdin);
//     printf("%p",Tamim);
//     return 0 ;
// }

// #include <stdio.h>
// #include <string.h>

// char tracks[][80] = {
//     "I left my heart in Harvard Med School",
//     "Newark, Newark - a wonderful town",
//     "Dancing with a Dork",
//     "From here to maternity",
//     "The girl from Iwo Jima",
// };

// void find_track(char search_for[]) {
//     for (int i = 0; i < 5; i++) {
//         if (strstr(tracks[i], search_for)) {
//             printf("track %i: '%s'\n", i, tracks[i]);
//         }
//     }
// }

// int main() {
//     char search_for[80];
//     printf("Search for: ");
//     fgets(search_for, 80, stdin);

//     // Remove trailing newline character if present
//     search_for[strcspn(search_for, "\n")] = '\0';

//     find_track(search_for);
//     return 0;
// }

// #include<stdio.h>

// int main(){
//     float latitude;
//     float longitude;
//     char info[80];
//     int started = 0 ;
//     puts ("data=[");
//     while (scanf("%f,%f,%79[^\n]",&latitude,&longitude,info)==3){
//         if (started)
//            printf(",\n");
//         else
//             started = 1 ;
//         printf("{latitude: %f, longitude:%f,info:'%s'}",latitude,longitude,info);

     
//     }
//     puts("\n");
//     return 0 ;

// // }
// #include<stdio.h>
// char main(){
//     char data[80];
//     fgets(data,80,stdin);
//     char dataset = 'y';
//     char datasets = 't';
    
//     switch (data[80])
//     {
//     case 'y':
//         puts("Train");
//         /* code */
//         break;
//     case 't':
//         puts("how are you");
//         break;    
//     default: 
//         puts("none");

//         break;
//     }
//     printf("name %s\n",data);
//     return 0 ;
// }

// #include<stdio.h>
// float total = 0.0;
// int count = 0;
// float tax_percent = 6.0;

// float add_with_tax(float f){
//     float tax_rate = 1 + tax_percent/100;
//     total = total+(f * tax_rate);
//     count = count +1 ;
//     return total;


// }
// int main(){
//     float val;
//     printf("Price of item:");
//     while(scanf("%f",&val)==1){
//         printf("total so far :%2f\n",add_with_tax(val));
//         printf("Price of item:");

//     }
//     printf("\nFinal total:%.2f\n",total);
//     printf("Number of item:%d\n",count);

//     return 0 ;
// }

// #include <stdio.h>
// #include "encrypt.h"

// int main() {
//     char msg[80];

//     printf("Enter message (Ctrl+D to exit):\n");

//     while (fgets(msg, sizeof(msg), stdin)) {
//         encrypt(msg);
//         printf("Encrypted: %s", msg);
//     }

//     return 0;
// }

// #include <stdio.h>
// #include <math.h>
// int main(){
    
//     double data;
//     double e = 1;
//     double x = 1; 
//     data = pow(e,2)+pow(e,-2)+sin(x)+4 / (5.0 * pow(x,4));
//     printf("%lf\n",data);
//     return 0 ;

// }

// #include<stdio.h>

// struct perferences{
//     const char *food;
//     float exercise_hours;
// };
//  struct fish {
//     const char *name;
//     const char *species;
//     int teeth;
//     int age;
//     struct preferences care; 
// };
// void catalog(struct fish f)
//     {
//         printf("%s is a %s whith %i teeth.He is %i\n",f.name,f.species,f.teeth,f.age);
//         printf("%s likes to eat %s.\n", f.name, f.care.food);
//         printf("%s likes to exercise for %.2f hours.\n", f.name, f.care.exercise_hours); 

//     }
//     void label(struct fish f) {
//     printf("Name: %s\nSpecies: %s\n", f.name, f.species);
// }
// int main(){
//      struct fish snappy = {"snappy", "piranha", 69, 4, {"meat", 7.5}};
//      catalog(snappy);
//      label(snappy);
//      return 0 ;
    
//     }
    

// #include <stdio.h>
// typedef struct {
//     const char *name;
//     const char *species;
//     int age;
// }turtle;
// void happy_birthday(turtle t){
//     t.age = t.age+1;
//     printf("Happy Birthday %s! You are now %i years old!\n",t.name,t.age);

// }
// int main(){
//     turtle myrtle = {"Myrtle","Leatherback sea turtle",99};
//     happy_birthday(myrtle);
//     printf("%s's age is Now %i\n",myrtle.name,myrtle.age);
//     return 0;
// }

// #include <stdio.h>

// // Correct type name is 'swage'
// typedef struct {
//     const char *description;
//     float value;
// } swage;

// // Now use 'swage *' properly here
// typedef struct {
//     swage *swag;
//     const char *sequence;
// } combination;

// typedef struct {
//     combination numbers;
//     const char *make;
// } safe;

// int main() {

//     swage gold = {"Gold!", 10000.0};
//     combination numbers = {&gold, "6502"};
//     safe s = {numbers, "ramacon250"};

//     printf("Safe Make: %s\n", s.make);
//     printf("Combination: %s\n", s.numbers.sequence);
//     printf("Prize: %s worth %.2f\n", (*s.numbers.swag).description, s.numbers.swag->value);

//     return 0;
// }
// #include<stdio.h>
// typedef enum{
//     COUNT, POUNDS,PINTS
// }unit_of_neasure;

// typedef union {
//     short count;
//     float weight;
//     float volume;
// }quantity;

// typedef struct{
//     const char *name;
//     const char *country;
//     quantity amount;
//     unit_of_neasure units;
// }fruit_order;

// void display(fruit_order order){
//     printf("THIS ORDER CONTAINS = ");
//     if(order.units == PINTS)
//        printf("%2.2f PINTS OF %s FROM %s\n",order.amount.volume,order.name,order.country);
//     else if(order.units == POUNDS)
//        printf("%2.2f ILB OF %s FROM %s\n",order.amount.weight,order.name,order.country);
//     else
//        printf("%i %s FROM %s\n",order.amount.count,order.name,order.country);
// }
// int main(){
//     fruit_order apples = {"APPLE","England",.amount.count=144,COUNT};
//     fruit_order strawberries = {"STRAWBERRIES","Spain",.amount.weight=17.6,POUNDS};
//     fruit_order oj = {"ORANGE JUICE","U.S.A",.amount.volume=10.5,PINTS};
//     display(apples);
//     display(strawberries);
//     display(oj);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// struct Node{
//     int data;           // hold data
//     struct Node* next;  // points to next node
// };
// int main(){                     //create 3 node
//     struct Node* head = NULL;
//     struct Node* secound = NULL;
//     struct Node* third = NULL;
//     // allocate memory
//     head = (struct Node*)malloc(sizeof(struct Node));
//     secound = (struct Node*)malloc(sizeof(struct Node));
//     third = (struct Node*)malloc(sizeof(struct Node));

//     //Assing data and link nodes
//     head->data = 100;
//     head->next = secound;
//     secound->data = 200;
//     secound->next = third;
//     third->data = 300;
//     third->next = NULL;
//     // print the list 

//     struct Node* temp = head;
//     while (temp!=NULL)
//     {
//         printf("%d = ",temp->data);
//         temp = temp->next;
//     }
//     printf("NULL\n");
//     return 0 ;    
    
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// typedef struct node {
//     char *question;
//     struct node *no;
//     struct node *yes;
// }node;
// int yes_no(char *question){
//     char answer[3];
//     printf("%s? (y/n):",question);
//     fgets(answer, 3, stdin);
//     return answer[0] == 'y';
// }
// node* create(char *question){
//    node *n = malloc(sizeof(node));
//    (n->question) = strdup(question);
//    n->no = NULL;
//    n->yes = NULL;
//    return n;
// }
// void release(node *n){
//     if (n){
//         if (n->no)
//            release(n->no);
//         if (n->yes)
//            release(n->yes);
//         if (n->question)
//            free(n->question);
//         free(n);
//     }
// }
// int main(){
//     char qustion[80];
//     char suspect[20];
//     node *start_node = create("Does suspect have a mustache");
//     start_node->no = create("Loretta Barnsworth");
//     start_node->yes = create("Vinny the Spoon");
//     node *current;
//     do{
//         current = start_node;
//         while(1){
//             if (yes_no(current->question)){
//                 if (current->yes){
//                     current = current->yes;
//                 }else{
//                     printf("SUSPECT IDENTIFIFD\n");
//                     break;
//                 }
//             }else if (current->no){
//                 current = current->no;
//             }else{
//                 printf("who the suspect?");
//                 fgets(suspect, 20, stdin);
//                 node *yes_node = create(suspect);
//                 current->yes = 
//             }
//         }
//     }
// }



// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// int compare_scores(const void* score_a,const void* score_b){
//     int a = *(int*)score_a;
//     int b = *(int*)score_b;
//     return a-b;
// }
// int compare_scores_desc(const void* score_a,const void* score_b){
//     int a = *(int*)score_a;
//     int b = *(int*)score_b;
//     return b-a;
// }
// typedef struct{
//     int width;
//     int height;
// }rectangle;

// int compare_areas(const void* a,const void* b){
//     rectangle* ra = (rectangle*)a;
//     rectangle* rb = (rectangle*)b;
//     int area_a = (ra->width * ra->height);
//     int area_b = (rb->width * rb->height);
//     return area_a - area_b;
// }
// int compare_names(const void* a, const void* b){
//     char** sa = (char**)a;
//     char** sb = (char**)b;
//     return strcmp(*sa,*sb);
// }
// int compare_areas_desc(const void* a, const void* b){
//     return compare_areas(b,a);
// }
// int compare_names_desc(const void* a, const void* b){
//     return compare_names(b,a);
// }
// int main(){
//     int scores[] = {239,77,888,9,000,3,112,333};
//     int i;
//     qsort(scores,8,sizeof(int),compare_scores);
//     qsort(scores,8,sizeof(int),compare_areas);
//     puts("THESE ARE THE SCORES IN ORDER");
//     for (i = 0; i < 8; i++){
//         printf("SCORE = %i\n", scores[i]);
//     }
//     char *name[] = {"Karen","Mark","Brett","Aolly"};
//     qsort(name,4,sizeof(char*),compare_names);
//     puts("THESE ARE THE NAMES IN ORDER:");
//     for(i = 0; i< 4;i++){
//         printf("%s\n",name[i]);
//     }
//     return 0 ;
// }

// #include <stdio.h>
// #include <stdarg.h>

// // Function that accepts a variable number of integers and prints them
// void print_numbers(int count, ...) {
//     va_list args;              // Declare a variable argument list
//     va_start(args, count);     // Initialize the list starting after 'count'

//     for (int i = 0; i < count; i++) {
//         int value = va_arg(args, int);  // Get the next argument (as int)
//         printf("%d ", value);
//     }

//     va_end(args);              // Clean up
//     printf("\n");
// }

// int main() {
//     print_numbers(3, 10, 20, 30);        // should print: 10 20 30
//     print_numbers(6, 1, 2, 7, 4, 5,3);     // should print: 1 2 3 4 5
//     return 0;
// }

// #include "entype.h"  

// int main() {
//     my_function();   
//     return 0;
// }

// #include<stdio.h>
// #include<stdlib.h>
// #include<time.h>
// char* now(){
//     time_t t;
//     time(&t);
//     return asctime(localtime(&t));
// }
// int main(){
//     char comment[80];
//     char cmd[120];
//     fgets(comment,80,stdin);
//     sprintf(cmd,"echo '%s %s'>>reports.log",comment,now());
//     system(cmd);
//     return 0;
// }

// #include<stdio.h>
// #include<stdlib.h>
// int main(int argc,char *argv[]){
//     printf("Diners: %s\n",argv[1]);
//     printf("Juice: %s\n",getenv("JUICE"));
//     return 0;
// }



// #include<stdio.h>
// #include<stdlib.h>
// int main(int argc, char *argv[]){
//     char *w = getenv("EXTRA");
//     if (!w){
//         w = getenv("FOOD");
//     }
//     if (!w){
//         w = argv[argc - 1];
//     }
//     char *c = getenv("EXTRA");
//     if (!c){
//         c = argv[argc - 1];
        
//     }
//     printf("%s with %s\n",c,w);
//     return 0 ;

// }

// #include<stdio.h>
// #include<stdlib.h>
// #include<unistd.h>
// #include<sys/types.h>
// #include<sys/wait.h>
// void open_url(char *url){
//     printf("Opening URL: %s\n",url);
// }
// int main(int argc, char *argv[]){
//     if (argc<2){
//         fprintf(stderr,"Usage: %s <search phrase>\n",argv[0]);
//         return 1;
//     }
//     char *phrase = argv[1];
//     char *vars[] = { "RSS_FEED=http://www.cnn.com/rss/celebs.xml", NULL };
//     int fd[2];
//     if (pipe(fd)==-1){
//         perror("pipe Failed");
//         return 1;
//     }
//     pid_t pid = fork();
//     if (pid == -1){
//         perror("can't fork process");
//         return 1;
//     }
//     if (pid == 0){
//         dup2(fd[1],STDOUT_FILENO);
//         close(fd[0]);
//         close(fd[1]);
//         if (execle("/usr/bin/python","python","./rssgossip.py","-u",
//         phrase,NULL,vars)==-1){
//             perror("can't run script");
//             exit(1);
//         }
//     }else{
//         close(fd[1]);
//         FILE *stream = fdopen(fd[0],"r");
//         char line[255];
//         while (fgets(line,sizeof(line),stream)){
//             if (line[0]=='\t'){
//                 open_url(line + 1);
//             }
//             fclose(stream);
//             wait(NULL);
//         }
//         return 0;
//     }


// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <netinet/in.h>
// #include <sys/socket.h>
// #include <time.h>

// int main() {
//     char *advice[] = {
//         "Take smaller bites\r\n",
//         "Go for the tight jeans. No they do NOT make you look fat.\r\n",
//         "One word: inappropriate\r\n",
//         "Just for today, be honest. Tell your boss what you *really* think\r\n",
//         "You might want to rethink that haircut\r\n"
//     };

//     srand(time(NULL));  // Seed for rand()

//     int listener_d = socket(PF_INET, SOCK_STREAM, 0);
//     if (listener_d == -1) {
//         perror("Can't open socket");
//         return 1;
//     }

//     struct sockaddr_in name;
//     name.sin_family = PF_INET;
//     name.sin_port = (in_port_t)htons(30000);
//     name.sin_addr.s_addr = htonl(INADDR_ANY);

//     if (bind(listener_d, (struct sockaddr *)&name, sizeof(name)) == -1) {
//         perror("Can't bind to socket");
//         return 1;
//     }

//     if (listen(listener_d, 10) == -1) {
//         perror("Can't listen");
//         return 1;
//     }

//     puts("Waiting for connections...");

//     while (1) {
//         struct sockaddr_storage client_addr;
//         socklen_t address_size = sizeof(client_addr);
//         int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);

//         if (connect_d == -1) {
//             perror("Can't accept connection");
//             continue;
//         }

//         char *msg = advice[rand() % 5];
//         send(connect_d, msg, strlen(msg), 0);
//         close(connect_d);
//     }

//     return 0;
// }
// #include<stdio.h>
// int main(){
//     int num;
    
//     scanf("%d",&num);
//     printf("%d",num);
    
// }

// #include <stdio.h>
// #include <stdlib.h>  // for abs()

// int main() {
//     int num[100];
//     int n;

//     // Get number of elements
//     printf("Enter number of elements: ");
//     scanf("%d", &n);

//     // Input elements
//     printf("Enter %d numbers: ", n);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &num[i]);
//     }

//     int make_defferace = 0;

//     // Calculate max difference between circular adjacent elements
//     for (int i = 0; i < n; i++) {
//         int next = (i + 1) % n;  // fix here
//         int deff = abs(num[i] - num[next]);  // absolute difference

//         if (deff > make_defferace) {
//             make_defferace = deff;
//         }
//     }

//     printf("Maximum difference: %d\n", make_defferace);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>  // for abs()

// int main() {
//     int num[100];
//     int n,x;
//     int i,found =-1;
//      // Get number of elements
//     printf("Enter number of elements: ");
//     scanf("%d", &n);

//     // Get the elements
//     printf("Enter %d numbers: ", n);
//     for (i = 0; i < n; i++) {
//         scanf("%d", &num[i]);
//     }
//     printf("ENTER NUMBER TO SCARCH =");
//     scanf("%d",&x);
//     for(int i=0;i<n;i++){
//         if (num[i]==x){
//             found = i;
//             break;
//         }
//     }
//     if (found!= -1){
//         printf("number found at index %d\n",found);
//     }else{
//         printf("Number not found.\n");
//     }
//     return 0;
   
// }