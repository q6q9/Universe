        package com.company;

        import java.util.Scanner;

        public class main3 {
            //отношение текущего к предыдущему элементу
            public static double h(int k,double x){
                    return (-(Math.pow(x,2)/(4*(Math.pow(x,2)+k))));
            }
            public static void main(String[] args) {
                Scanner in = new Scanner(System.in);
                System.out.println("Введите эпсилум (0<e<1):");
                double e = in.nextDouble();
                while (!(e>0&&1>e)){
                    System.out.println("Неверно. Введите эпсилум:");
                    e = in.nextDouble();
                }
                System.out.println("Введите икс (x!=0):");
                double x = in.nextDouble();
                while (!(x!=0)){
                    System.out.println("Неверно. Введите икс:");
                    x = in.nextDouble();
                }
                int k=0;
                double summ= x/2, second=summ, first=0  ;
                while (Math.abs(first-second)>=e)
                {
                    first = second;
                    k++;
                    second = second * h(k,x);
                    summ += second;
                }
                System.out.printf("Сумма = %f\nКол-во слагаемых - %d", summ,k+1);
            }
        }







