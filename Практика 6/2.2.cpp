#include <iostream>
using namespace std;

int main() {
    int n, m, w;
    cin >> n >> m >> w; // Читаем размеры поля (строки, столбцы) и количество грибов

    char a[32][32]; // Создаем табличку (максимум 32 на 32)

    //Сначала заполняем ВСЮ табличку нулями (символами '0')
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = '0';
        }
    }

    for (int k = 0; k < w; k++) {
        int r, c;
        cin >> r >> c;
        a[r - 1][c - 1] = '*'; // Вычитаем 1, потому что в программах счет идет с нуля, а не с единицы
    }

    // ШАГ 3: Идем по каждой клетке и считаем соседей
    for (int i = 0; i < n; i++) {       // Проходим по каждой строке
        for (int j = 0; j < m; j++) {   // Проходим по каждому столбцу
            
            if (a[i][j] == '*') {       
                cout << '*';            
            } else {                    
                int count = 0;          
                
                if (i > 0 && a[i - 1][j] == '*') count++;
                if (i < n - 1 && a[i + 1][j] == '*') count++;
                if (j > 0 && a[i][j - 1] == '*') count++;
                if (j < m - 1 && a[i][j + 1] == '*') count++;
                if (i > 0 && j > 0 && a[i - 1][j - 1] == '*') count++;
                if (i > 0 && j < m - 1 && a[i - 1][j + 1] == '*') count++;
                if (i < n - 1 && j > 0 && a[i + 1][j - 1] == '*') count++;
                if (i < n - 1 && j < m - 1 && a[i + 1][j + 1] == '*') count++;
                
                cout << count;
            }
        }
        cout << endl;
    }
    
    return 0;
}
