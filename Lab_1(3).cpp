#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;


int main() {
  srand(time(0));

  int n;
  cout << "Введіть кількість точок ";
  cin >> n;
  int points[n][2];;

  // Генеруємо випадкові координати точок
  for (int i = 0; i < n; i++) {
      points[i][0]  = rand() % 21 - 10; //
      points[i][1]  = rand() % 21 - 10; //  
  }
  for (int i = 0; i < n; i++) {
      cout << points[i][0] << "  " ;
      cout << points[i][1] << endl ;
  }

  int xa, ya, xb, yb, xc, yc;
  cout << "Введіть координати точки А ";
  cin >> xa >> ya;
  cout << "Введіть координати точки B ";
  cin >> xb >> yb;
  cout << "Введіть координати точки C ";
  cin >> xc >> yc;


  // Обчислюємо площу трикутника ABC
  float ABC = abs((xa*(yb-yc) + xb*(yc-ya) + xc*(ya-yb))/2.0);
  int point = 0;

    for (int i = 0; i < n; i++) {
      float ABP = abs((xa*(yb-points[i][1]) + xb*(points[i][1]-ya) + points[i][0]*(ya-yb))/2.0);
      float BCP = abs((points[i][0]*(yb-yc) + xb*(yc-points[i][1]) + xc*(points[i][1]-yb))/2.0);
      float CAP = abs((xa*(points[i][1]-yc) + points[i][0]*(yc-ya) + xc*(ya-points[i][1]))/2.0);

      if (ABP + BCP + CAP == ABC) {
         point++;
      }
    }

    cout << "Кількість точок всередині трикутника: " << point << endl;

    return 0;
  }


