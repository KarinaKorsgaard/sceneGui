//
//  scene.h
//  SceneGui
//
//  Created by Karina Jensen on 13/04/16.
//
//

#ifndef scene_h
#define scene_h

#include "subScene.h"
#include "defines.h"

class Scene{
    public:
    int mode;
    string name;
    vector<SubScene>subs;
    
    string explanation="explanation";
    
    vector<ofColor>colors;
    
    bool consentual;
    bool weighed;
    bool substractive;
    int totalPoints;
    
    int amountOfSubs;
    int globalTimer;
    bool useGlobalAligners;
    bool useNumbers;
    bool useImages;
    
    //aligners;
    //ALIGNERS: seperate from parameters!
    int matrixX;
    int matrixY;
    
    int timerX;
    int timerY;
    
    int timerSize;
    int liveResultFontSize;
    int explanationFontSize;
    int legendFontSize;
    int chartFontSize;
    int questionFontSize;
    int resultFontSize;
    int headLineFontSize;
    
    int liveResultX;
    int liveResultY;
    
    int legendX;
    int legendY;
    
    int explanationX; //text2
    int explanationY;
    
    int headlineX; //text1
    int headlineY;
    
    
    int top10chartAssesmentX;
    int top10chartAssesmentY;
    
    int top10chartQuizX;
    int top10chartQuizY;
    
    int questionX;
    int questionY;
    
    int collumWidth1;
    int collumWidth2;
    int collumWidth3;
    

    
    
    void setup(int _mode, string n){
        mode = _mode;
        name = n;
        vector<string>empty;
        vector<int>image;
        for(int i = 0; i< MAX_SUB;i++){
            ofColor c;
            colors.push_back(c);
            image.push_back(0);
            empty.push_back("initial value");
        }
        for(int i = 0; i< MAX_SUB;i++){
            addNewSub("",empty,image);
        }
    }
    
    void setSubQuestion(int q, string s){
        if(q<subs.size())subs[q].question = s;
    }
    
    void setSubAnswer(int sub, int ans, string s){
        if(sub<subs.size()){
            if(ans<subs[sub].answerOptions.size()){
                subs[sub].answerOptions[ans] = s;
            }
        }
    }
    
    int getNumSubs(){
        return amountOfSubs;
    }
    
    void setexplanation(string s){
        explanation = s;
        cout << explanation +" text 1 of "+name << endl;
    }
    

    
    //only used for setup... 
    void addNewSub(string q, vector<string>a,vector<int>img){
        SubScene sub = *new SubScene;
        sub.setup(q,a,img);
        sub.amountAnswerOptions = 1;
        subs.push_back(sub);
    }
};

#endif /* scene_h */
