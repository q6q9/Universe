package com.company;

import java.util.HashMap;
import java.util.Scanner;
import java.util.Map;

public class Main {


    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Введите предложение:");
        String str = in.nextLine();
        System.out.println("Введите кол-во повторяемых слов для их удаления:");
        int n = in.nextInt();
        String[] words = str.split(" ");

        Map<String, Integer> occurrences = new HashMap<String, Integer>();

        for (String word : words) {
            Integer oldCount = occurrences.get(word);
            if (oldCount == null) {
                oldCount = 0;
            }
            occurrences.put(word, oldCount + 1);
        }

        for (Map.Entry<String, Integer> a : occurrences.entrySet()) {
            if (a.getValue() == n) {
                str = str.replaceAll(a.getKey(), "");
            }
        }
        System.out.println(str);
    }
}

