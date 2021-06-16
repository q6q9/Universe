package com.company;

import java.util.Scanner;

public class main4 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Введите кол-во строк и столбцев:");
        int m = in.nextInt();
        int[][] array = new int[m][m];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                System.out.printf("Введите элемент [%d][%d]:\n", i+1, j+1);
                array[i][j] = in.nextInt();
            }
        }
        System.out.printf("Матрица: \n");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                System.out.printf("%d  ",array[i][j]);
            }

            System.out.printf("\n");
        }

        int max=array[0][1];

        for (int i = 0; i < m-1; i++) {
            for (int j = i+1; j < m; j++) {
                if (array[i][j]>max){max=array[i][j];}
            }
        }

        int min = array[1][0];
        for (int i = 0; i < m-1; i++) {
            for (int j = i+1; j < m; j++) {
                if (array[j][i]<min){min=array[i][j];}
            }
        }


        System.out.printf("Максимум - %d\n Минимум - %d\n", max,min);
    }

}
