#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <ctime>

using namespace std;

//Structure to keep track of various locations
struct Point
{
  int x;
  int y;

  Point(int _x, int _y): x(_x), y(_y)
  {

  }
};

//Structure for the Player object
struct Player
{
  int food;
  int health;
  bool alive;
  int x;
  int y;

  Player() : food(64), health(10), alive(true)
  {}
  void loseHealth()
  {
    if(health>0)
      health--;
    if(health==0)
      alive = false;
  }
  void gainHealth()
  {
    if(health<10)
      health++;
  }
};

typedef const int cint;         //Google typedef to see what this means
typedef const Point cPoint;
char* Wall;

char* create_dungeon(int, int, Point&, Point&);      //Creates the dungeon
void traversal(char*, Point&, cPoint&, cint, cint); //Used for moving inside dungeon
void combat(Player&, int);  //Used for simulating combat
void trap_statements();  //3 statements that show at random when the player activates a trap
void food_statements();  //3 statements that show at random when the player finds food
void hit_statements();   //3 statements that show at random when the player hits enemy
void get_hit_statements();//3 statements that show at random when the player gets hit

int main ()
{
  srand(time(0));

  int width = 0;
  int height = 0;

  cout<<"Enter the width and size of the dungeon you want to play in: " <<endl;
  cout<<"Please try to keep it bigger than a 8 x 8 grid for best experience." <<endl;

  cout <<"Height :" <<endl;
  cin >> height ;
  cout <<"Width :" <<endl;
  cin >> width ;

  Point start_point(0,0);
  Point exit_point(0,0);

  char* dungeon = NULL;

  int n = width*height;
  Wall = new char[n];
  for(int i = 0; i<(n); i++)
  {
      Wall[i] = ' ';
  }
  dungeon = create_dungeon(width, height, start_point, exit_point);


  traversal(dungeon, start_point, exit_point, width, height);

 delete dungeon ;

  return 0;
}

void trap_statements()
{
  int i = rand()%3 ;
  if(i = 0)
  {
      cout<<"a" <<endl;
  }
  if(i = 1)
  {
      cout<<"b" <<endl;
  }
  if(i = 2)
  {
      cout<<"c" <<endl;
  }
}

void food_statements()
{
  int j = rand()%3 ;
  if(j = 0)
  {
      cout<<"a" <<endl;
  }
  if(j = 1)
  {
      cout<<"b" <<endl;
  }
  if(j = 2)
  {
      cout<<"c" <<endl;
  }
}

void hit_statements()
{
  int k = rand()%3 ;
  if(k = 0)
  {
      cout<<"a" <<endl;
  }
  if(k = 1)
  {
      cout<<"b" <<endl;
  }
  if(k = 2)
  {
      cout<<"c" <<endl;
  }
}

void get_hit_statements()
{
  int l = rand()%3 ;
  if(l = 0)
  {
      cout<<"a" <<endl;
  }
  if(l = 1)
  {
      cout<<"b" <<endl;
  }
  if(l = 2)
  {
      cout<<"c" <<endl;
  }
}

void traversal(char* dungeon, Point& start_point, cPoint& exit_point,
	       cint width, cint height)
{

    Player PlayerObject ;
   int n = width* height;
   for(int i=0; i<n; i++){
   int y = rand() % 100;
   if(y < 20)
   {
    int v = rand() % 100 ;

    if(v > 0 && v < 15)
   {
           if(Wall[i] != 'w'&& Wall[i]!='P' &&Wall[i]!= 'X')
           {
               Wall[i] = 'E' ;
           }
       //}
   };

   if(v > 15 && v < 30)
   {
           if(Wall[i] != 'w'&& Wall[i]!='P' &&Wall[i]!= 'X')
           {
               if (Wall[i] != 'E')
               {

                   Wall[i] = 'H';
               }
           }
       //}
   }

   if(v > 30 && v < 45)
   {
           if(Wall[i] != 'w'&& Wall[i]!='P' &&Wall[i]!= 'X')
           {
               if (Wall[i] != 'E')
               {
                   if (Wall[i] != 'H')
                   {
                       Wall[i] = 'T' ;
                   }
               }
           }
       //}

   }

   if(v > 45 && v < 60)
   {
           if(Wall[i] != 'w'&& Wall[i]!='P' &&Wall[i]!= 'X')
           {
               if (Wall[i] != 'E')
               {
                   if (Wall[i] != 'H')
                   {
                       if (Wall[i] != 'T')
                       {
                           Wall[i] = 'F' ;


                       }
                   }
               }
           }
       //}
   }
   if(v > 60)
   {
           if(Wall[i] != 'w'&& Wall[i]!='P' &&Wall[i]!= 'X')
           {
               if (Wall[i] != 'E')
               {
                   if (Wall[i] != 'H')
                   {
                       if (Wall[i] != 'T')
                       {
                           if (Wall[i] != 'F')
                           {
                               Wall[i] = 'w' ;
                           }


                       }
                   }
               }
           //}
   }

   }
   }
   else{
        Wall[i] == ' ';

   }

   }


for (int i = 0; i < n ; i++)
{

    cout<<endl;
   for(int j=0; j<width*height; j++){
    if(j%width == 0){
        cout<<endl;
    }
    cout<<Wall[j];
   }

cout<<endl;
cout<<endl;


cout<< "U,D,L,R :" << endl;
char a;
cin >> a;
int tempNewPosition = 0;
int tempNewIndex = 0;
if (a == 'x')
    {
        cout<< "You Died!!" ;
        break;
    }
    if (a == 'R')
    {
       // food = food - 1;

      // cout<<"You have " << PlayerObject.food << " food left" <<endl;
        int index = (start_point.y * width) + start_point.x;

        Wall[index] = ' ';
        int tempPosition = start_point.x + 1;
        tempNewPosition = (start_point.y * width) + tempPosition;
        if(Wall[tempNewPosition] != 'w')
            {
                 if(Wall[tempNewPosition] == 'H')
                 {
                        PlayerObject.gainHealth();
                 }
        if(Wall[tempNewPosition] == 'T')
            {
            PlayerObject.loseHealth();
            trap_statements();
        }
        if(Wall[tempNewPosition] == 'F')
        {
            int a = (rand() % 5) + 4;
             PlayerObject.food += a ;

            food_statements();

        }
        if(Wall[tempNewPosition] =='E')
        {
            int z = (rand()%3) + 2;
            cout<<"You will fight "<< z <<"enemies" <<endl;
            combat(PlayerObject,z);
        }

        if(Wall[tempNewPosition] == 'X')
        {
            cout<< "You Win";
            break;
        }


                start_point.x = start_point.x+1;
                int newIndex = (start_point.y * width) + start_point.x;
                Wall[newIndex] = 'P';
                }

                else
                {
                    Wall[index] = 'P';

                }
              PlayerObject.food-=1;
              cout<<"You have " << PlayerObject.food << " food left" <<endl;

    }
    if (a == 'L')
    {

//food = food - 1;
//cout<<"You have "<< PlayerObject.food << " food left" <<endl;
         int index = (start_point.y * width) + start_point.x;
        Wall[index] = ' ';
        int newPosition = start_point.x-1;
         tempNewPosition = (start_point.y * width) + newPosition;
        if(Wall[tempNewPosition] != 'w'){
                 if(Wall[tempNewPosition] == 'H')
        {
            PlayerObject.gainHealth();
        }
        if(Wall[tempNewPosition] == 'T')
        {
            PlayerObject.loseHealth();
            trap_statements();
        }
        if(Wall[tempNewPosition] == 'F')
        {
            int a = (rand() % 5) + 4;
            PlayerObject.food +=  a ;
            food_statements();

        }
        if(Wall[tempNewPosition] == 'E')
        {
            int z = (rand()%3) + 2;
            cout<<"You will fight "<< z <<"enemies" <<endl;
            combat(PlayerObject,z);
        }
        if(Wall[tempNewPosition] == 'X')
        {
            cout<< "You Win";
            break;
        }

         start_point.x = start_point.x-1;
        int newIndex = (start_point.y * width) + start_point.x;
        Wall[newIndex] = 'P';
        }

        else{
            Wall[index] = 'P';
        }
        PlayerObject.food-=1;
        cout<<"You have " << PlayerObject.food << " food left" <<endl;
    }
    if (a == 'U')
    {

       //cout<<"You have "<< PlayerObject.food << " food left" <<endl;
        int index = (start_point.y * width) + start_point.x;
        Wall[index] = ' ';

        int tempPosition = start_point.y-1;
         tempNewIndex = (tempPosition * width) + start_point.x;
        if(Wall[tempNewIndex] != 'w')
        {
             if(Wall[tempNewIndex] == 'H')
        {
            PlayerObject.gainHealth();
        }
        if(Wall[tempNewIndex] == 'T')
        {
            PlayerObject.loseHealth();
            trap_statements();
        }
        if(Wall[tempNewIndex] == 'F')
        {
            int a = (rand() % 5) + 4;
           PlayerObject.food += a ;
            food_statements();

        }
        if(Wall[tempNewIndex] == 'E')
        {
            int z = (rand()%3) + 2;
            cout<<"You will fight "<< z <<"enemies" <<endl;
            combat(PlayerObject,z);
        }
        if(Wall[tempNewIndex] == 'X')
        {
            cout<< "You Win";
            break;
        }


        start_point.y = start_point.y-1;
        int newIndex = (start_point.y * width) + start_point.x;
        Wall[newIndex] = 'P';
        }

        else{
            Wall[index] = 'P';
           // PlayerObject.loseHealth();
        }
      PlayerObject.food-=1;
      cout<<"You have " << PlayerObject.food << " food left" <<endl;
    }
    if (a == 'D')
    {

      // cout<<"You have "<< PlayerObject.food << " food left" <<endl;
        int index = (start_point.y * width) + start_point.x;
        Wall[index] = ' ';
        int  tempPosition = start_point.y+1;
         tempNewIndex = (tempPosition * width) + start_point.x;
        if(Wall[tempNewIndex] != 'w'){
                 if(Wall[tempNewIndex] == 'H')
        {
            PlayerObject.gainHealth();
        }
        if(Wall[tempNewIndex] == 'T')
        {
            PlayerObject.loseHealth();
            trap_statements();
        }
        if(Wall[tempNewIndex] == 'F')
        {
            int a = (rand() % 5) + 4;
            PlayerObject.food +=  a ;
            food_statements();

        }
        if(Wall[tempNewIndex] == 'E')
        {
            int z = (rand()%3) + 2;
            cout<<"You will fight "<< z <<"enemies" <<endl;
            combat(PlayerObject,z);
        }
        if(Wall[tempNewIndex] == 'X')
        {
            cout<< "You Win";
            break;
        }


        start_point.y = start_point.y+1;
        int newIndex = (start_point.y * width) + start_point.x;
        Wall[newIndex] = 'P';
        }

        else{
        Wall[index] = 'P';
        //PlayerObject.loseHealth() ;
        }
      PlayerObject.food-=1;
      cout<<"You have " << PlayerObject.food << " food left" <<endl;

    }



    if(PlayerObject.health == 0 )
    {
        cout << "You Died because food is finished !!" ;
    }
    if(PlayerObject.food == 0)
    {
        cout<< "You Died because food is finished !!" ;
    }


}


}
void combat(Player& player, int enemies)
{
while(enemies > 0)
{int c = rand() % 100;
  if(c <= 30)
  {
      hit_statements();
      enemies = enemies - 1;
  }
  if(c <= 10)
  {
      get_hit_statements();
      player.loseHealth();
  }
}
}

char* create_dungeon(int width, int height, Point& ref_startPoint, Point& ref_exitPoint)
{

    int n = width*height;

    for(int i=0; i<width; i++)
   {
     Wall[i] = 'w';

   }

   cout<<endl;
    int counter = 0;
   for(int i=width; i<n-width; i++ ){
     if(i%width != 0 && i%width != width-1){
     }
     else{
       Wall[i] = 'w';
       counter ++;
         if(counter == 2){
       counter=0;
     }
     }

   }
   for(int i=0; i<width; i++){
     Wall[n-width+i]= 'w';
    // cout<<Wall[n-width+i];
   }
     bool isPlaced = false;
    cout<<endl;

    int randomNumber = rand() % (height-2);
    while (true)
    {
        if(randomNumber <= 0)
        {
            randomNumber = rand() % (height-2);
        }
        else{
            break;
        }
    }
    ref_startPoint.x = 1;
    ref_startPoint.y = randomNumber;
    int index = (randomNumber * width) + 1;


    if(Wall[index] != 'w'){
        Wall[index] = 'P';
        isPlaced = true;
//        break;
    }
    else if(isPlaced == false){
        Wall[width+1] = 'P';
    }




    bool isExitPlaced = false;

    int randomNumbery = rand() % (height-1);
    while (true)
    {
        if(randomNumbery <= 0)
        {
            randomNumbery = rand() % (height-2);
        }
        else{
            break;
        }
    }

    ref_exitPoint.x = width - 2;
    ref_exitPoint.y = randomNumbery;


    int indexy = (ref_exitPoint.y * width) + ref_exitPoint.x;
    if(Wall[indexy] != 'w'){
        Wall[indexy] = 'X';
        isExitPlaced = true;
        //break;

   }
    else if(isExitPlaced == false){
            int filterWidth = width -1;
        int BottomRightPosition = n-width-2;
        Wall[BottomRightPosition] = 'X';
    }

    return Wall ;

}

