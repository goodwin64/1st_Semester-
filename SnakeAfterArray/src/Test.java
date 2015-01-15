public class Test {
    public static void main(String[] args) {
        int n = 6;  // размер матрицы
        int[][] m = new int[n][n];
        // центр
        int i = n / 2;
        int j = n / 2;
        // задаем границы движения 
        int min_i = i; int max_i = i; // влево вправо
        int min_j = j; int max_j = j; // вверх вниз
        int d = 0; // сначала пойдем влево
        for (int a = 1; a < n * n; a++) {
            m[i][j] = a;
            switch (d) {
                case 0:
                    i -= 1;  // движение влево
                    if (i < min_i) { // проверка выхода за заполненную центральную часть слева
                        d = 1; // меняем направление
                        min_i = i; // увеличиваем заполненную часть влево
                    }
                    break;
                case 1:  // движение вверх проверка сверху        
                    j -= 1;
                    if (j < min_j) {
                        d = 2;
                        min_j = j;
                    }
                    break;
                case 2:  // движение вправо проверка справа
                    i += 1;
                    if (i > max_i) {
                        d = 3;
                        max_i = i;
                    }
                    break;
                case 3:  // движение вниз проверка снизу
                    j += 1;
                    if (j > max_j) {
                        d = 0;
                        max_j = j;
                    }
            }
        }
        
        for (int k = 0; k < n; k++) {
            for (int v = 0; v < n; v++) 
                System.out.print(m[k][v] + "\t");
            System.out.println();
        }
    }
}