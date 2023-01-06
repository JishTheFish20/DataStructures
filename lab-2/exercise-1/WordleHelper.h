#ifndef WORDLE_HELPER_H
#define WORDLE_HELPER_H

#include <stdexcept>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class WordleHelper{
 
    std::vector<std::string> allowed;
    std::vector<std::string> answers;

    std::vector<std::string> green;
    std::vector<std::string> yellow;
    std::vector<std::string> gray;


    bool contains(std::string word, char c){
        for (int i = 0; i < word.length(); i++){
            if (word[i] == c){
                return true;
            }
        }

        return false;
    }

public:
    WordleHelper(){
        std::string answersFile = "answers.txt";
        std::string allowedFile = "allowed.txt";

        std::fstream newfile;

        newfile.open(answersFile, std::ios::in);
        if (newfile.is_open()){
            std::string tp;
            
            while(getline(newfile, tp)){
                answers.push_back(tp);
            }
            newfile.close();
        }
        else {
            throw std::logic_error("Cant read file " + answersFile + ".");
        }

        newfile.open(allowedFile, std::ios::in);
        if (newfile.is_open()){
            std::string tp;
            
            while(getline(newfile, tp)){
                allowed.push_back(tp);
            }
            newfile.close();
        }
        else {
            throw std::logic_error("Cant read file " + allowedFile + ".");
        }
    }

    void addGreen(std::string feedback){
        if (feedback.size() != 5){
            throw std::logic_error("Green feedback must be exactly 5 characters");
        }
        if (std::any_of(feedback.begin(), feedback.end(), [](char c){
            return c != '_' && (c < 'a' || c > 'z');
        })){
            throw std::logic_error("Green feedback must contain only lowercase letters or underscores");
        }

        green.push_back(feedback);
    }

    void addYellow(std::string feedback){
        if (feedback.size() != 5){
            throw std::logic_error("Yellow feedback must be exactly 5 characters");
        }
        if (std::any_of(feedback.begin(), feedback.end(), [](char c){
            return c != '_' && (c < 'a' || c > 'z');
        })){
            throw std::logic_error("Yellow feedback must contain only lowercase letters or underscores");
        }

        yellow.push_back(feedback);
    }

    void addGray(std::string feedback){
        if (std::any_of(feedback.begin(), feedback.end(), [](char c){
            return c < 'a' && c > 'z';
        })){
            throw std::logic_error("Yellow feedback must contain only lowercase letters");
        }

        gray.push_back(feedback);
    }

    std::vector<std::string>possibleSolutions(){

        std::cout << "Green: "<< green[0] << std::endl;
        std::cout << "Yellow: "<< yellow[0] << std::endl;
        std::cout << "Gray: "<< gray[0] << std::endl;
 
        std::vector<std::string> possibleSolutionBank;

        int greenTotal = 0;
        int yellowTotal = 0;

        for(int i = 0; i < 5; i++){ //counts how many green and yellow letters there are
            if(green[0][i] != '_'){
                greenTotal++;
            }
            if(yellow[0][i] != '_'){
                yellowTotal++;
            }
            for(int j = 0; j < 5; j++){ //checks the difference between the green and yellow letters
                if((green[0][j] == yellow[0][i]) && yellow[0][i] != '_'){
                    std::cout << yellow[0][i] << std::endl;
                    yellow[0][i] = '_'; //replace letters in yellow that are already in green
                    yellowTotal--;// lower the yellow count
            }
          }
        }
        for(int i = 0; i < answers.size(); i++){ //checks every solution
            bool isGray = false; 
            int yellowCount = 0;
            int greenCount = 0;
             for(int j = 0; j < 5; j++){ // checks how many of the green letters a current word in the bank has
                if(answers[i][j] == green[0][j]){
                    greenCount++;
                }
                for(int k = 0; k < 5; k++){ // checks how many of the green letters a current word in the bank has
                    if((answers[i][j] == yellow[0][k]) && (answers[i][j] != yellow[0][j])){
                        yellowCount++;
                    }
                }
                for(int k = 0; k < (gray[0]).length(); k++){ //checks to see if a word has gray letters
                    if(answers[i][j] == gray[0][k]){
                        isGray = true;
                    }
                }
             }
             //if the word has enough yellow and green letters and does not have any gray letter pass it through
             if((greenCount == greenTotal) && (yellowCount >= yellowTotal) && !isGray){
                 possibleSolutionBank.push_back(answers[i]);
             }
        }
        return possibleSolutionBank;
    }

    std::vector<std::string> suggest(){
        // Optionally, your code here...
        return {"bring", "words", "close"};
    }

    ~WordleHelper(){

    }
    friend struct WordleTester;
};
#endif