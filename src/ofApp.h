#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "scene.h"
#include "ofxClipboard.h"
#include "defines.h"
#include "ofxXmlSettings.h"
#include "ofxDatGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void onTextInputEvent(ofxDatGuiTextInputEvent e);
        void onButtonEvent(ofxDatGuiButtonEvent e);
        void onDropdownEvent(ofxDatGuiDropdownEvent e);
        void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
    
    vector<string>imageStrings;
    vector<ofImage>imgs;
    void saveToXml();
    void loadFromXml();
    
    vector<int>retardedCounters;
    
    ofxDatGuiTheme* enabled;
    ofxDatGuiTheme* disabled;
    
    ofxXmlSettings xml;
    string dataFolder;
    void updateSubScene(SubScene* s);
    void updateScene(Scene* s);
    void updateGlobalAligners();
    void updateLocalAligners(Scene* s);
    
    void updateGuiToSceneAligners(Scene s);
    
    void setSceneAlignersToXml(Scene s, ofxXmlSettings* xml); //just avoiding too much clutter in main
    void setGlobalAlignersToXml(ofxXmlSettings* xml);
    
    void setGlobalAlignersFromXml(ofxXmlSettings xml);
    void setSceneAlignersFromXml(Scene* s,ofxXmlSettings xml);
    
    void addNewScene(int mode, string name);
    
    void setGuiToSceneValues(int scene);
    void setSubGuiToSubValues(int sub);
    
    vector<string>sceneNames;
    vector<string>imagesString;
    vector<string>tableNames;
    
    ofParameter<bool>addVote;
    ofParameter<bool>addQuiz;
    ofParameter<bool>addAssesment;
    ofParameter<bool>save;
    vector<ofParameter<bool>>editExisting;
    
    //scene paramters
    ofParameter<int>amountOfSubs;
    ofParameter<int>globalTimer;
    vector<ofParameter<bool>>editExistingSub;
    ofParameter<bool>useGlobalAligners;
    
    ofParameter<bool>weighed;
    ofParameter<int>totalPoints;
    ofParameter<bool>consentual;
    ofParameter<bool>substractive;
    
    //subscene parameters:
    ofParameter<int>amountAnswerOptions;
    ofParameter<bool>useNumbers;
    ofParameter<bool>useImages;
    ofParameter<bool>useGlobalTimer;
    ofParameter<int>localTimer;
    ofParameter<int>rightAnswer; 
    
    //guis
    ofxPanel mainGui;
    ofxPanel sceneGui1;
    ofxPanel sceneGui2;
    ofxPanel sceneGui3;
    ofxPanel subSceneGui;
    
    ofxPanel globalAligners; // for SEQUENCE
    //ofxPanel localAligners; // for SCENE
    
    ofxDatGui* tableNamesGui; //12, applies for SEQUENCE. + toggle-use;
    
    ofxDatGui* colorSelector; //there are ten, top ones  are used first. - applied for SCENE!
    ofxDatGui* sceneTextEditorGui;
    
    ofxDatGui* imageSelector; //there are 10, top ones are used first. - applies for SUBSCENE? - only visible if useImages!
    ofxDatGui* subsceneTextEditorGui;


    
    ofxDatGui* DatSub;
    ofxDatGui* DatScene;
    
    vector<bool>toggleScene;
    bool showSome = false; //showing subsceneGui
    bool globalAlignerToggle = true;
    //ofxPanel subSceneGui1;
    //ofxPanel subSceneGui2;
    //ofxPanel subSceneGui3;
    
    //subGui: ADD . - hide the ones you are not using? . color differently maybe ? 
    //text1, text2
    //toggles for weighed, laalla . all that.
    
    
 
    
    //subscene guis: static
    //toggle numbers:
    //toggle images:
    //DATgui tableNames// for each answer
    // DATgui dropdown. -- : Linked to answerOptions, MAX_NUM ! - this is local for each sub in xml
    //Dat gui colors - for each answer --- local for each sub in xml...
    //textinput for question. - 1, then change which one you are editing.
    
    //dynamic_
    //answeroptions - define num answers? or add textinput field? - lets make 10 and then setVisible...
    
    bool b_sceneGui1;
    bool b_sceneGui2;
    bool b_sceneGui3;
    
    bool b_subSceneGui1;
    bool b_subSceneGui2;
    bool b_subSceneGui3;

    
    vector<Scene> scenes;

    int whichScene;
    int whichSub;
    
    
    
    
    
    
    //ALIGNERS: seperate from parameters!
    int matrixX;
    int matrixY;
    
    int timerX;
    int timerY;
    
    int timerSize;
    int liveResultFontSize;
    int headLineFontSize;
    int explanationFontSize;
    int legendFontSize;
    int chartFontSize;
    int questionFontSize;
    int resultFontSize;
    
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
    
    //ALIGNERS: seperate from parameters!
    ofParameter<int> p_matrixX;
    ofParameter<int> p_matrixY;
    
    ofParameter<int> p_timerX;
    ofParameter<int> p_timerY;
    
    ofParameter<int> p_timerSize;
    ofParameter<int> p_liveResultFontSize;
    ofParameter<int> p_explanationFontSize;
    ofParameter<int> p_legendFontSize;
    ofParameter<int> p_chartFontSize;
    ofParameter<int> p_questionFontSize;
    ofParameter<int> p_resultFontSize;
    ofParameter<int> p_headLineFontSize;
    
    ofParameter<int> p_liveResultX;
    ofParameter<int> p_liveResultY;
    
    ofParameter<int> p_legendX;
    ofParameter<int> p_legendY;
    
    ofParameter<int> p_explanationX; //text2
    ofParameter<int> p_explanationY;
    
    ofParameter<int> p_headlineX; //text1
    ofParameter<int> p_headlineY;
    
    ofParameter<int> p_top10chartAssesmentX;
    ofParameter<int> p_top10chartAssesmentY;
    
    ofParameter<int> p_top10chartQuizX;
    ofParameter<int> p_top10chartQuizY;
    
    ofParameter<int> p_questionX;
    ofParameter<int> p_questionY;
    
    ofParameter<int> p_collumWidth1;
    ofParameter<int> p_collumWidth2;
    ofParameter<int> p_collumWidth3;
		
};
