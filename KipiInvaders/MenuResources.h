#ifndef MENURESOURCES_H_INCLUDED
#define MENURESOURCES_H_INCLUDED

#include "Background.h"
#include "Button.h"
#include "InputField.h"
#include "Keyboard.h"

//Game Background
extern Background gGameBackground;

//Main Menu
extern Button gPlayButton;
extern Button gControlsButton;
extern Button gRankingButton;
extern Button gExitButton;

//Game Mode Menu
extern Button gClassicGameModeButton;
extern Button gSurvivalGameModeButton;
extern Button gBackButton;

//Pause Menu
extern Button gResumeButton;
extern Button gMainMenuButton;

//Controls Menu
extern Texture gControlsMenuText[3];
/* extern Button gBackButton; */

//Game Over Menu
extern Button gNewGameButton;
extern Texture gGameOverMenuText;
/* extern Button gMainMenuButton; */

//Submit Name And Score Menu
extern Texture gFinalScoreText;
extern Texture gFinalScoreDigits;
extern Texture gSubmitMenuText;
extern InputField gSubmitMenuInputField;
extern Button gSubmitButton;
extern Keyboard gKeyboard;

//Ranking Menu
extern Texture gRankingMenuSign;
extern Texture p1NameTexture;
extern Texture p1ScoreTexture;
extern Texture p2NameTexture;
extern Texture p2ScoreTexture;
extern Texture p3NameTexture;
extern Texture p3ScoreTexture;
extern Texture p4NameTexture;
extern Texture p4ScoreTexture;
extern Texture p5NameTexture;
extern Texture p5ScoreTexture;
extern Texture p6NameTexture;
extern Texture p6ScoreTexture;
extern Texture p7NameTexture;
extern Texture p7ScoreTexture;
extern Texture p8NameTexture;
extern Texture p8ScoreTexture;
extern Texture p9NameTexture;
extern Texture p9ScoreTexture;
extern Texture p10NameTexture;
extern Texture p10ScoreTexture;
/* extern Button gBackButton; */


#endif // MENURESOURCES_H_INCLUDED
