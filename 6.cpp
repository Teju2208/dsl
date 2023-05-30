/*There are flight paths between cities. If there is a flight between city A and city B
then there is an edge between the cities. The cost of the edge can be the time that
flight take to reach city B from A, or the amount of fuel used for the journey.
Represent this as a graph. The node can be represented by airport name or name of the
city. Use adjacency list representation of the graph or use adjacency matrix
representation of the graph. Check whether the graph is connected or not. Justify the
storage representation used.*/

#include <iostream>
#include <string.h>
using namespace std;
class flight
{
public :
 int am[10][10];
 char city_index[10][10];
 flight();
 int create();
 void display(int city_count);
};
flight::flight()
{
 int i, j;
for (i = 0; i < 10; i++)
{
 strcpy(city_index[i], "xx");
 }
 for (i = 0; i < 10; i++)
{
 for (j = 0; j < 10; j++)
{
 am[i][j] = 0;
 }
 }
}
int flight::create()
{
int city_count = 0, j, si, di, wt;
 char s[10], d[10], c;
 do
{
 cout << "\n\nEnter Source City : ";
 cin >> s;
 cout << "\nEnter Destination City : ";
 cin >> d;
 for (j = 0; j < 10; j++)
{
 if (strcmp(city_index[j], s) == 0)
 break;
 }
if (j == 10)
{
 strcpy(city_index[city_count], s);
 city_count++;
 }
for (j = 0; j < 10; j++)
{
 if (strcmp(city_index[j], d) == 0)
 break;
 }
 if (j == 10)
{
 strcpy(city_index[city_count], d);
 city_count++;
 }
 cout << "\nEnter Distance From " << s << " And " << d << " : ";
 cin >> wt;
 for (j = 0; j < 10; j++)
{
 if (strcmp(city_index[j], s) == 0)
 si = j;
 if (strcmp(city_index[j], d) == 0)
 di = j;
 }
 am[si][di] = wt;
 cout << "\nDo you want to add more cities.....(y/n) : ";
 cin >> c;
 } while (c == 'y' || c == 'Y');
 return (city_count);
}
void flight::display(int city_count)
{
 int i, j;
cout << "\n\nDisplaying Adjacency Matrix : \n\n";
 cout <<"\t\t " << city_index[0];
 for (i = 1; i < city_count; i++)
 cout <<"\t " << city_index[i];
 cout << "\n\n";
 for (i = 0; i < city_count; i++)
{
 cout <<city_index[i];
 for (j = 0; j < city_count; j++)
{
 cout << "\t\t" << am[i][j];
 }
 cout << "\n\n";
 }
}
int main()
{
flight f;
 int n, city_count;
 char c;
 do
{
 cout << "\n***** Flight Main Menu *****";
 cout << "\n\n1.Create Graph\n2.Display Adjacency Matrix\n3.Exit";
 cout << "\n\nEnter your choice : ";
 cin >> n;
 switch (n)
{
 case 1 : city_count = f.create();
 break;
 case 2 : f.display(city_count);
 break;
 case 3 : return 0;
 }
 cout << "\nDo you Want to Continue in Main Menu....(y/n) : ";
 cin >> c;
 } while (c == 'y' || c == 'Y');
 return 0;
}
