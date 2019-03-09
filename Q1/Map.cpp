#include "Map.h"
#include <iostream>
#include <math.h>
Map::Map(int n)
{
  this->N = n;
  arr = new int*[N];
  for(int i{}; i < N; i++)
    arr[i] = new int[N];
  std::cout<<"Here"<<std::endl;
  for(int i{}; i < N ; i++)
    {
      for(int j{};j < N ; j++)
	{
	  arr[i][j] = (rand() % 100);
	}
    }
}
Map::Map(const Map& map)
{
  std::cout << "Copy Constructor!"<<std::endl;
  N = map.N;
  arr = new int* [N];
  for(int i{}; i < N ; i++)
    {
      arr[i] = new int[N];
    }
  for(int i{}; i < N; i++)
    {
      for(int j{}; j < N ; j++)
	arr[i][j] = map.arr[i][j];
    }
}
void Map::showMap()
{
  std::cout << "Map Created!"<<std::endl;
  for(int a{}; a < N ; a++)
    {
      for(int b{}; b < N; b++)
	{
	  std::cout << arr[a][b] << " ";
	}
      std::cout << std::endl;
    }
  
}
int Map::findRoutea()
{
  int x{};
  int y{};
  int dif{};
  int next{1};
  while(next)
    {
      if(x < N || y < N)
	{
         int difr = abs(arr[x][y] - arr[x + 1][y]);
         int difd = abs(arr[x][y] - arr[x][y + 1]);
         if(difr < difd)
	   {
	     x++;
	     dif = dif + difr;
	      
	   }
	 else
	   {
	     y++;
	     dif = dif + difd;
	     
	   }
	}
      if(x != (N - 1) && y == (N - 1) )
	{
	  for(int j{x}; j < (N - 1); j++)
	    {
	      dif = dif + (abs(arr[x][y] - arr[x + 1][y]));
	      x++;
	     
	    }
	}
      if( y != (N - 1) && x == (N - 1))
	{
	  for(int j{y}; j < (N - 1); j++)
	    {
	      dif = dif + (abs(arr[x][y] - arr[x][y + 1]));
	      y++;
	     
	    }
	}
      if(y == (N - 1) && x == (N - 1))
	next = 0;
    }
  return dif;
}
int Map::findRouteb()
 {
  int x{};
  int y{};
  int dif{};
  int next{1};
  while(next)
    {
      if(x < N || y < N)
	{
         int difr = abs(arr[x][y] - arr[x + 1][y]);
         int difd = abs(arr[x][y] - arr[x][y + 1]);
	 int difrd = abs(arr[x][y] - arr[x + 1][y + 1]);
         if(difr < difd)
	   {
	     if(difr < difrd)
	       {
		 x++;
		 dif = dif + difr;
	       }
	     else
	       {
		 x++;
		 y++;
		 dif = dif + difrd;
	       }
	   }
	 else
	   {
	     if(difd < difrd)
	       {
		 y++;
		 dif = dif + difd;
	       }
	     else
	       {
		 y++;
		 x++;
		 dif = dif + difrd;
	       }
	   }
	}
      if(x != (N - 1) && y == (N - 1) )
	{
	  for(int j{x}; j < (N - 1); j++)
	    {
	      dif = dif + (abs(arr[x][y] - arr[x + 1][y]));
	      x++;
	     
	    }
	}
      if( y != (N - 1) && x == (N - 1))
	{
	  for(int j{y}; j < (N - 1); j++)
	    {
	      dif = dif + (abs(arr[x][y] - arr[x][y + 1]));
	      y++;
	     
	    }
	}
      if(y == (N - 1) && x == (N - 1))
	next = 0;
    }
  return dif;
}
int Map::findRoutec()
{
  std::cout << "Fuck" << std::endl;
  int var{1};
  int var1{1};
  int dif{};
  int u{N - 1};
  std::cout << "fuck" << std::endl;
  for(int i{1}; i <= 2 * (N - 1); i++ )
    {
      var = var * i;
    }
  for(int i{1}; i < (N -1); i++ )
    {
      var1 = var1 * 1;
    }
  var = var/(2 *(var1));
  int arrdif[var];
  for(int i{}; i < N ; i++) //for first y
    {
      std::cout << "shit" << std::endl;
      for(int dd1{}; dd1 < i; dd1++) //first dif in y
	{
	  dif = dif +abs(arr[0][dd1] - arr[0][dd1 + 1]);
	}
      for(int j{ N-1 }; j > -1; j--) //first x
	{
	  std::cout << "4 Gold" << std::endl;
	  for(int dr1{}; dr1 <= j ;dr1++) //diff first x
	    {
	      dif = dif + abs(arr[dr1][i] - arr[dr1 + 1][i]);
	      std::cout << dr1 << std::endl;
	    }
	  std::cout << "Hichi" <<std::endl;
	  if(j == u)
	    {
	      std::cout << "Hichi" << std::endl;
	      for(int dd2{i}; dd2 < (N - 1); dd2++)//if in first x attempt we reach end
		{
		  dif = dif + abs(arr[N - 1][dd2] - arr[N -1][dd2 + 1]);
		  std::cout << "Hoy" << std::endl;
		}
	    }
	  else //if x is still not N-1
	    {
	      std::cout << "Hi" << std::endl;
	    }
	}
    }
  arrdif[0] = 5;
  std::cout << arrdif[0];
}
void Map::showRoutea()
{
   int x{};
  int y{};
  int dif{};
  int next{1};
  char arrshow[N][N];
    for(int i{}; i < N ;i++)
    {
      for(int j{}; j < N ;j++)
	arrshow[i][j] = '-';
    }
  while(next)
    {
      if(x < N || y < N)
	{
         int difr = abs(arr[x][y] - arr[x + 1][y]);
         int difd = abs(arr[x][y] - arr[x][y + 1]);
         if(difr < difd)
	   {
	     x++;
	     dif = dif + difr;
	     arrshow[x][y] = '*'; 
	   }
	 else
	   {
	     y++;
	     dif = dif + difd;
	     arrshow[x][y] = '*';
	   }
	}
      if(x != (N - 1) && y == (N - 1) )
	{
	  for(int j{x}; j < (N - 1); j++)
	    {
	      dif = dif + (abs(arr[x][y] - arr[x + 1][y]));
	      x++;
	      arrshow[x][y] = '*';
	    }
	}
      if( y != (N - 1) && x == (N - 1))
	{
	  for(int j{y}; j < (N - 1); j++)
	    {
	      dif = dif + (abs(arr[x][y] - arr[x][y + 1]));
	      y++;
	      arrshow[x][y] = '*';
	    }
	}
      if(y == (N - 1) && x == (N - 1))
	next = 0;
    }
  arrshow[0][0] = '*';
  for(int i{}; i < N ; i++)
    {
      for(int j{}; j < N; j++)
	{
	  std::cout << arrshow[i][j] << " ";
	}
      std::cout << std::endl;
    }
  
}
void Map::showRouteb()
 {
  int x{};
  int y{};
  int dif{};
  int next{1};
   char arrshow[N][N];
    for(int i{}; i < N ;i++)
    {
      for(int j{}; j < N ;j++)
	arrshow[i][j] = '-';
    }
  while(next)
    {
      if(x < N || y < N)
	{
         int difr = abs(arr[x][y] - arr[x + 1][y]);
         int difd = abs(arr[x][y] - arr[x][y + 1]);
	 int difrd = abs(arr[x][y] - arr[x + 1][y + 1]);
         if(difr < difd)
	   {
	     if(difr < difrd)
	       {
		 x++;
		 dif = dif + difr;
		 arrshow[x][y] = '*';
	       }
	     else
	       {
		 x++;
		 y++;
		 dif = dif + difrd;
		 arrshow[x][y] = '*';
	       }
	   }
	 else
	   {
	     if(difd < difrd)
	       {
		 y++;
		 dif = dif + difd;
		 arrshow[x][y] = '*';
	       }
	     else
	       {
		 y++;
		 x++;
		 dif = dif + difrd;
		 arrshow[x][y] = '*';
	       }
	   }
	}
      if(x != (N - 1) && y == (N - 1) )
	{
	  for(int j{x}; j < (N - 1); j++)
	    {
	      dif = dif + (abs(arr[x][y] - arr[x + 1][y]));
	      x++;
	      arrshow[x][y] = '*';
	     
	    }
	}
      if( y != (N - 1) && x == (N - 1))
	{
	  for(int j{y}; j < (N - 1); j++)
	    {
	      dif = dif + (abs(arr[x][y] - arr[x][y + 1]));
	      y++;
	      arrshow[x][y] = '*';
	     
	    }
	}
      if(y == (N - 1) && x == (N - 1))
	next = 0;
    }
   arrshow[0][0] = '*';
  for(int i{}; i < N ; i++)
    {
      for(int j{}; j < N; j++)
	{
	  std::cout << arrshow[i][j] << " ";
	}
      std::cout << std::endl;
    }
}
Map::~Map()
{
  std::cout<<"i'm dying.."<<std::endl;
  for(int i = 0; i < N; i++)
    {
    delete[] arr[i];
    }
delete[] arr;
}
