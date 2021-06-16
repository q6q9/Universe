package com.company;

import java.util.Scanner;

public class main2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Введите кол-во строк:");
        int m = in.nextInt();
        System.out.println("Введите кол-во столбцов:");
        int n = in.nextInt();
        int[][] array = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.printf("Введите элемент [%d][%d]:\n", i + 1, j + 1);
                array[i][j] = in.nextInt();
            }
        }
        System.out.printf("Матрица: \n");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.printf("%d  ", array[i][j]);
            }

            System.out.printf("\n");
        }

        int s;
        for (int i = 0; i < n; i++) {
            s = 0;
            for (int j = 0; j < m; j++) {
                s += array[j][i];
            }
            array[0][i] = s;
        }

        int w = 0, k = 0;

        for (int i = 0; i < n; i++) {
            w = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (array[0][i] != -13373) {
                    if (array[0][i] == array[0][j]) {
                        w++;
                        array[0][j] = -13373;
                    }
                }
            }
            if (w > 1) k += w;
        }
        System.out.printf("Кол-во столбцов с одинаковой суммой элементов: %d", k);
    }
}
/*
5
        5
        6
        5
        3
        6
        0
        0
        0
        0
        0
        0
        0
 */