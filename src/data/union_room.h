// const rom data

ALIGNED(4) static const u8 sText_EmptyString[] = _("");
ALIGNED(4) const u8 sText_Colon[] = _(":");
ALIGNED(4) const u8 sText_ID[] = _("{ID}");
ALIGNED(4) const u8 sText_PleaseStartOver[] = _("Por favor, reinicia la comunicación.");
ALIGNED(4) const u8 sText_WirelessSearchCanceled[] = _("La comunicación inalámbrica\nfue cancelada.");
ALIGNED(4) const u8 sText_AwaitingCommunucation2[] = _("Awaiting communication\nfrom another player."); // Unused
ALIGNED(4) const u8 sText_AwaitingCommunication[] = _("¡{STR_VAR_1}! Esperando\ncomunicación con el otro jugador.");
ALIGNED(4) const u8 sText_AwaitingLinkPressStart[] = _("¡{STR_VAR_1}! ¡Esperando invitados!\nCuando todos estén listos, presiona START.");
ALIGNED(4) const u8 sJPText_SingleBattle[] = _("シングルバトルを かいさいする");
ALIGNED(4) const u8 sJPText_DoubleBattle[] = _("ダブルバトルを かいさいする");
ALIGNED(4) const u8 sJPText_MultiBattle[] = _("マルチバトルを かいさいする");
ALIGNED(4) const u8 sJPText_TradePokemon[] = _("ポケモンこうかんを かいさいする");
ALIGNED(4) const u8 sJPText_Chat[] = _("チャットを かいさいする");
ALIGNED(4) const u8 sJPText_DistWonderCard[] = _("ふしぎなカードをくばる");
ALIGNED(4) const u8 sJPText_DistWonderNews[] = _("ふしぎなニュースをくばる");
ALIGNED(4) const u8 sJPText_DistMysteryEvent[] = _("ふしぎなできごとを かいさいする"); // Unused
ALIGNED(4) const u8 sJPText_HoldPokemonJump[] = _("なわとびを かいさいする");
ALIGNED(4) const u8 sJPText_HoldBerryCrush[] = _("きのみマッシャーを かいさいする");
ALIGNED(4) const u8 sJPText_HoldBerryPicking[] = _("きのみどりを かいさいする");
ALIGNED(4) const u8 sJPText_HoldSpinTrade[] = _("ぐるぐるこうかんを かいさいする");
ALIGNED(4) const u8 sJPText_HoldSpinShop[] = _("ぐるぐるショップを かいさいする");

// Unused
const u8 *const sJPLinkGroupActionTexts[] = {
    sJPText_SingleBattle,
    sJPText_DoubleBattle,
    sJPText_MultiBattle,
    sJPText_TradePokemon,
    sJPText_Chat,
    sJPText_DistWonderCard,
    sJPText_DistWonderNews,
    sJPText_DistWonderCard,
    sJPText_HoldPokemonJump,
    sJPText_HoldBerryCrush,
    sJPText_HoldBerryPicking,
    sJPText_HoldBerryPicking,
    sJPText_HoldSpinTrade,
    sJPText_HoldSpinShop
};

const u8 sText_1PlayerNeeded[] = _("1 jugador\nnecesario.");
const u8 sText_2PlayersNeeded[] = _("2 jugadores\nnecesarios.");
const u8 sText_3PlayersNeeded[] = _("3 jugadores\nnecesarios.");
const u8 sText_4PlayersNeeded[] = _("4 jugadores\nnecesarios.");
const u8 sText_2PlayerMode[] = _("MODO\n2-JUGADORES");
const u8 sText_3PlayerMode[] = _("MODO\n3-JUGADORES");
const u8 sText_4PlayerMode[] = _("MODO\n4-JUGADORES");
const u8 sText_5PlayerMode[] = _("MODO\n5-JUGADORES");

static const u8 *const sPlayersNeededOrModeTexts[][5] = {
    // 2 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode
    }, 
    // 4 players required
    {
        sText_3PlayersNeeded,
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_4PlayerMode
    }, 
    // 2-5 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    }, 
    // 3-5 players required
    {
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    }, 
    // 2-4 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode
    }
};

ALIGNED(4) const u8 sText_BButtonCancel[] = _("{B_BUTTON}Salir");
ALIGNED(4) const u8 sJPText_SearchingForParticipants[] = _("ため\nさんかしゃ ぼしゅうちゅう です！"); // Unused, may have been cut off
ALIGNED(4) const u8 sText_PlayerContactedYouForXAccept[] = _("{STR_VAR_2} se contactó desde\n{STR_VAR_1}. ¿Aceptar?");
ALIGNED(4) const u8 sText_PlayerContactedYouShareX[] = _("{STR_VAR_2}te contactó.\n¿Compartir {STR_VAR_1}?");
ALIGNED(4) const u8 sText_PlayerContactedYouAddToMembers[] = _("{STR_VAR_2} te contactó.\n¿Agregar al grupo?");
ALIGNED(4) const u8 sText_AreTheseMembersOK[] = _("¡{STR_VAR_1}!\n¿Están bien estos integrantes?");
ALIGNED(4) const u8 sText_CancelModeWithTheseMembers[] = _("¿Cancelar MODO {STR_VAR_1}?");
ALIGNED(4) const u8 sText_AnOKWasSentToPlayer[] = _("Se le invió una confirmación\na {STR_VAR_1}.");
ALIGNED(4) const u8 sText_OtherTrainerUnavailableNow[] = _("El otro entrenador no parece\nestar disponible ahora…\p");
ALIGNED(4) const u8 sText_CantTransmitTrainerTooFar[] = _("No puedes comunicarte con\nun entrenador tan lejos.\p");
ALIGNED(4) const u8 sText_TrainersNotReadyYet[] = _("Los integrantes no están\nlistos.\p");

static const u8 *const sCantTransmitToTrainerTexts[] = {
    [UR_TRADE_PLAYER_NOT_READY - 1]  = sText_CantTransmitTrainerTooFar,
    [UR_TRADE_PARTNER_NOT_READY - 1] = sText_TrainersNotReadyYet
};

ALIGNED(4) const u8 sText_ModeWithTheseMembersWillBeCanceled[] = _("El MODO {STR_VAR_1} será\ncancelado.{PAUSE 60}");
ALIGNED(4) const u8 sText_MemberNoLongerAvailable[] = _("Un integrante no\npuede seguir participando.\p");

static const u8 *const sPlayerUnavailableTexts[] = {
    sText_OtherTrainerUnavailableNow,
    sText_MemberNoLongerAvailable
};

ALIGNED(4) const u8 sText_TrainerAppearsUnavailable[] = _("El otro jugador no parece\nestar disponible…\p");
ALIGNED(4) const u8 sText_PlayerSentBackOK[] = _("¡{STR_VAR_1} envió una confirmación!");
ALIGNED(4) const u8 sText_PlayerOKdRegistration[] = _("{STR_VAR_1} OK'd your registration as\na member.");
ALIGNED(4) const u8 sText_PlayerRepliedNo[] = _("{STR_VAR_1} dijo que no…\p");
ALIGNED(4) const u8 sText_AwaitingOtherMembers[] = _("¡{STR_VAR_1}!\n¡Esperando más participantes!");
ALIGNED(4) const u8 sText_QuitBeingMember[] = _("¿Dejar el grupo?");
ALIGNED(4) const u8 sText_StoppedBeingMember[] = _("Dejaste el grupo.\p");

static const u8 *const sPlayerDisconnectedTexts[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_MemberNoLongerAvailable,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_TrainerAppearsUnavailable,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = sText_StoppedBeingMember
};

ALIGNED(4) const u8 sText_WirelessLinkEstablished[] = _("Se estableció la\ncomunicación inalámbrica.");
ALIGNED(4) const u8 sText_WirelessLinkDropped[] = _("Se terminó la\ncomunicación inalambrica…");
ALIGNED(4) const u8 sText_LinkWithFriendDropped[] = _("Se terminó la conexión con tu\namigo…");
ALIGNED(4) const u8 sText_PlayerRepliedNo2[] = _("{STR_VAR_1} respondió que no…");

const u8 *const sLinkDroppedTexts[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_LinkWithFriendDropped,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_LinkWithFriendDropped,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo2,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = NULL
};

ALIGNED(4) const u8 sText_DoYouWantXMode[] = _("¿Aceptas el\nMODO {STR_VAR_2}?");
ALIGNED(4) const u8 sText_DoYouWantXMode2[] = _("¿Aceptas el\nMODO {STR_VAR_2}?");

// Unused
static const u8 *const sDoYouWantModeTexts[] = {
    sText_DoYouWantXMode,
    sText_DoYouWantXMode2
};

ALIGNED(4) const u8 sText_CommunicatingPleaseWait[] = _("Communicating…\nPlease wait."); // Unused
ALIGNED(4) const u8 sText_AwaitingPlayersResponseAboutTrade[] = _("Esperando respuesta de {STR_VAR_1} sobre\nel intercambio…");
ALIGNED(4) const u8 sText_Communicating[] = _("Estableciendo comunicación con{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) const u8 sText_CommunicatingWithPlayer[] = _("Estableciendo comunicación con {STR_VAR_1}{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) const u8 sText_PleaseWaitAWhile[] = _("Espere por favor{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");

static const u8 *const sCommunicatingWaitTexts[] = {
    sText_Communicating,
    sText_CommunicatingWithPlayer,
    sText_PleaseWaitAWhile
};

ALIGNED(4) const u8 sText_HiDoSomethingMale[] = _("¡Hey! ¿Hay algo que\nquieras hacer?");
ALIGNED(4) const u8 sText_HiDoSomethingFemale[] = _("¡Hola!\n¿Quíeres hacer algo?");
ALIGNED(4) const u8 sText_HiDoSomethingAgainMale[] = _("{STR_VAR_1}: ¡Nos volvemos a ver!\n¿Qué hacemos hoy?");
ALIGNED(4) const u8 sText_HiDoSomethingAgainFemale[] = _("{STR_VAR_1}: ¡Hola {PLAYER}!\n¿Hacemos algo?");

static const u8 *const sHiDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_HiDoSomethingMale,
        sText_HiDoSomethingFemale
    }, {
        sText_HiDoSomethingAgainMale,
        sText_HiDoSomethingAgainFemale
    }
};

ALIGNED(4) const u8 sText_DoSomethingMale[] = _("¿Hacemos algo?");
ALIGNED(4) const u8 sText_DoSomethingFemale[] = _("¿Hacemos Algo?");
ALIGNED(4) const u8 sText_DoSomethingAgainMale[] = _("{STR_VAR_1}: ¿Que hacemos\nahora?");
ALIGNED(4) const u8 sText_DoSomethingAgainFemale[] = _("{STR_VAR_1}: ¿Hacemos algo más?"); // Unused

// Unused
static const u8 *const sDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_DoSomethingMale,
        sText_DoSomethingFemale
    }, {
        sText_DoSomethingAgainMale,
        sText_DoSomethingAgainMale // was probably supposed to be sText_DoSomethingAgainFemale
    }
};

ALIGNED(4) const u8 sText_SomebodyHasContactedYou[] = _("Te han contactado.{PAUSE 60}");
ALIGNED(4) const u8 sText_PlayerHasContactedYou[] = _("{STR_VAR_1} te contactó.{PAUSE 60}");

static const u8 *const sPlayerContactedYouTexts[] = {
    sText_SomebodyHasContactedYou,
    sText_PlayerHasContactedYou
};

ALIGNED(4) const u8 sText_AwaitingResponseFromTrainer[] = _("Esperando respuesta\ndel otro entrenador…");
ALIGNED(4) const u8 sText_AwaitingResponseFromPlayer[] = _("Esperando respuesta de\n{STR_VAR_1}…");

static const u8 *const sAwaitingResponseTexts[] = {
    sText_AwaitingResponseFromTrainer,
    sText_AwaitingResponseFromPlayer
};

ALIGNED(4) const u8 sText_ShowTrainerCard[] = _("El entrenador te mostró\nsu FICHA ENTRENADOR.\p¿Le enseñas\ntu FICHA ENTRENADOR?");
ALIGNED(4) const u8 sText_BattleChallenge[] = _("El entrenador te desafía a\nun combate.\p¿Aceptas el desafío?");
ALIGNED(4) const u8 sText_ChatInvitation[] = _("El entrenador quiere\nhabar contigo.\p¿Quieres iniciar\nla conversación?");
ALIGNED(4) const u8 sText_OfferToTradeMon[] = _("Alguien quiere intercambiar tu\n{DYNAMIC 1} Nv. {DYNAMIC 0}\ppor\n{DYNAMIC 3} Nv. {DYNAMIC 2}.\p¿Aceptas el trato?");
ALIGNED(4) const u8 sText_OfferToTradeEgg[] = _("Alguien solicita intercambiar\ntu Huevo.\l¿Aceptas el intercambio?");
ALIGNED(4) const u8 sText_ChatDropped[] = _("Se interrumpió la conversación.\p");
ALIGNED(4) const u8 sText_OfferDeclined1[] = _("Te rechazaron la oferta.\p");
ALIGNED(4) const u8 sText_OfferDeclined2[] = _("Rechazaste la oferta.\p");
ALIGNED(4) const u8 sText_ChatEnded[] = _("Se terminó la conversación.\p");

// Unused
static const u8 *const sInvitationTexts[] = {
    sText_ShowTrainerCard,
    sText_BattleChallenge,
    sText_ChatInvitation,
    sText_OfferToTradeMon
};

ALIGNED(4) const u8 sText_JoinChatMale[] = _("¡Hola! Estamos conversando.\n¿Quíeres unirte?");
ALIGNED(4) const u8 sText_PlayerJoinChatMale[] = _("{STR_VAR_1}: ¡Hola {PLAYER}!\nEstamos conversando.\l¿Te unes a nosotros?");
ALIGNED(4) const u8 sText_JoinChatFemale[] = _("¡Hola! Estamos en una conversación.\n¿Te unes a nosotros?");
ALIGNED(4) const u8 sText_PlayerJoinChatFemale[] = _("{STR_VAR_1}: ¡Hola, {PLAYER}!\nEstamos hablando.\l¿Te unes a la conversación?");

static const u8 *const sJoinChatTexts[][GENDER_COUNT] = {
    {
        sText_JoinChatMale,
        sText_JoinChatFemale
    }, {
        sText_PlayerJoinChatMale,
        sText_PlayerJoinChatFemale
    }
};

ALIGNED(4) const u8 sText_TrainerAppearsBusy[] = _("……\nEl entrenador parece estar en otra cosa…\p");
ALIGNED(4) const u8 sText_WaitForBattleMale[] = _("¿Un combate, eh?\nSeguro, dame unos segundos.");
ALIGNED(4) const u8 sText_WaitForChatMale[] = _("¿Hablar, eh?\nSeguro, déjame prepararme.");
ALIGNED(4) const u8 sText_ShowTrainerCardMale[] = _("¡Seguro! Aqui tienes\nmi FICHA ENTRENADOR.");
ALIGNED(4) const u8 sText_WaitForBattleFemale[] = _("¿Un Combate? ¡Seguro!\ndame unos segundos.");
ALIGNED(4) const u8 sText_WaitForChatFemale[] = _("¿Quieres hablar?\nPor supesto, en un rato.");
ALIGNED(4) const u8 sText_ShowTrainerCardFemale[] = _("Como presentación\nte muestro mi FICHA ENTRENADOR.");

static const u8 *const sText_WaitOrShowCardTexts[GENDER_COUNT][4] = {
    {
        sText_WaitForBattleMale,
        sText_WaitForChatMale,
        NULL,
        sText_ShowTrainerCardMale
    }, {
        sText_WaitForBattleFemale,
        sText_WaitForChatFemale,
        NULL,
        sText_ShowTrainerCardFemale
    }
};

ALIGNED(4) const u8 sText_WaitForChatMale2[] = _("You want to chat, huh?\nSure, just wait a little."); // Unused
ALIGNED(4) const u8 sText_DoneWaitingBattleMale[] = _("¡Gracias por esperar!\n¡Comencemos!{PAUSE 60}");
ALIGNED(4) const u8 sText_DoneWaitingChatMale[] = _("¡Listo!\n¡Hablemos!{PAUSE 60}");
ALIGNED(4) const u8 sText_DoneWaitingBattleFemale[] = _("¡Perdón por la espera!\n¡Comencemos!{PAUSE 60}");
ALIGNED(4) const u8 sText_DoneWaitingChatFemale[] = _("¡Gracias por esperar!\nConversemos.{PAUSE 60}");
ALIGNED(4) const u8 sText_TradeWillBeStarted[] = _("Comenzando el intercambio.{PAUSE 60}");
ALIGNED(4) const u8 sText_BattleWillBeStarted[] = _("Comenzando la batalla.{PAUSE 60}");
ALIGNED(4) const u8 sText_EnteringChat[] = _("Iniciando conversación…{PAUSE 60}");

static const u8 *const sStartActivityTexts[][GENDER_COUNT][3] = {
    {
        {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }, {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }
    }, {
        {
            sText_DoneWaitingBattleMale,
            sText_DoneWaitingChatMale,
            sText_TradeWillBeStarted
        }, {
            sText_DoneWaitingBattleFemale,
            sText_DoneWaitingChatFemale,
            sText_TradeWillBeStarted
        }
    }
};

ALIGNED(4) const u8 sText_BattleDeclinedMale[] = _("¡Perdón! Mis POKéMON no parecen\nverse bien ahora.\lLuchemos en otro momento.\p");
ALIGNED(4) const u8 sText_BattleDeclinedFemale[] = _("Mis POKéMON no se encuentran bien\nen estos momentos…\pLuchemos en otra ocasión.\p");

const u8 *const sBattleDeclinedTexts[GENDER_COUNT] = {
    sText_BattleDeclinedMale,
    sText_BattleDeclinedFemale
};

ALIGNED(4) const u8 sText_ShowTrainerCardDeclinedMale[] = _("¿Mi FICHA ENTRENADOR?…\n¿Donde la tendré?\l¡Perdón, te la enseño en otro momento!\p");
ALIGNED(4) const u8 sText_ShowTrainerCardDeclinedFemale[] = _("¿Dónde habré puesto mi\nFICHA ENTRENADOR?…\l¡Perdón! No la encuentro\p");

const u8 *const sShowTrainerCardDeclinedTexts[GENDER_COUNT] = {
    sText_ShowTrainerCardDeclinedMale,
    sText_ShowTrainerCardDeclinedFemale
};

ALIGNED(4) const u8 sText_IfYouWantToDoSomethingMale[] = _("Si quieres hacer algo conmigo\n¡solo dímelo!\p");
ALIGNED(4) const u8 sText_IfYouWantToDoSomethingFemale[] = _("Si quieres hacer algo conmigo\navisa, no seas tímido.\p");

const u8 *const sIfYouWantToDoSomethingTexts[GENDER_COUNT] = {
    sText_IfYouWantToDoSomethingMale,
    sText_IfYouWantToDoSomethingFemale
};

ALIGNED(4) const u8 sText_TrainerBattleBusy[] = _("¡Ups! Recordé que tengo\nque hacer algo.\lEn otro momento, ¿Si?\p");
ALIGNED(4) const u8 sText_NeedTwoMonsOfLevel30OrLower1[] = _("Para combatir necesitas\ndos POKéMON menores al\lNv. 30.\p");
ALIGNED(4) const u8 sText_NeedTwoMonsOfLevel30OrLower2[] = _("Para combatir necesitas\ndos POKéMON menores al\lNv. 30.\p");

ALIGNED(4) const u8 sText_DeclineChatMale[] = _("Oh, claro.\nHablamos cuando quieras\p");
ALIGNED(4) const u8 stext_DeclineChatFemale[] = _("Oh…\nNos vemos en otro momento.\p");

// Response from partner when player declines chat
static const u8 *const sDeclineChatTexts[GENDER_COUNT] = {
    sText_DeclineChatMale,
    stext_DeclineChatFemale
};

ALIGNED(4) const u8 sText_ChatDeclinedMale[] = _("¡Perdón!\nJusto ahora no puedo.\lHablemos en otro momento.\p");
ALIGNED(4) const u8 sText_ChatDeclinedFemale[] = _("Lo siento.\nTengo cosas que hacer ahora.\lHablemos en otra ocasión.\p");

// Response from partner when they decline chat
static const u8 *const sChatDeclinedTexts[GENDER_COUNT] = {
    sText_ChatDeclinedMale,
    sText_ChatDeclinedFemale
};

ALIGNED(4) const u8 sText_YoureToughMale[] = _("¡Wow!\n¡Se ve que eres muy fuerte!\p");
ALIGNED(4) const u8 sText_UsedGoodMoveMale[] = _("¿Usaste eso?\n¡Que estratega!\p");
ALIGNED(4) const u8 sText_BattleSurpriseMale[] = _("¡Oh!\n¡Fue sorprendente!\p");
ALIGNED(4) const u8 sText_SwitchedMonsMale[] = _("¿Cómo puedes usar ese\nPOKéMON dada la situación?\p");
ALIGNED(4) const u8 sText_YoureToughFemale[] = _("Ese POKéMON…\n¡Se ve muy sano!\p");
ALIGNED(4) const u8 sText_UsedGoodMoveFemale[] = _("¡Eso es!\n¡Es la mejor opción!\p");
ALIGNED(4) const u8 sText_BattleSurpriseFemale[] = _("¡Asombroso!\n¿Cómo haces eso?\p");
ALIGNED(4) const u8 sText_SwitchedMonsFemale[] = _("¡Es el momento perfecto para\ncambiar POKéMON!\p");

const u8 *const sBattleReactionTexts[GENDER_COUNT][4] = {
    {
        sText_YoureToughMale,
        sText_UsedGoodMoveMale,
        sText_BattleSurpriseMale,
        sText_SwitchedMonsMale
    }, 
    {
        sText_YoureToughFemale,
        sText_UsedGoodMoveFemale,
        sText_BattleSurpriseFemale,
        sText_SwitchedMonsFemale
    }
};

ALIGNED(4) const u8 sText_LearnedSomethingMale[] = _("¡Ya veo!\n¡Que educativo!\p");
ALIGNED(4) const u8 sText_ThatsFunnyMale[] = _("¡Deja de hacerme reír!\n¡Me duele el estómago!\p");
ALIGNED(4) const u8 sText_RandomChatMale1[] = _("¿Eh?\nAlgo pasó.\p");
ALIGNED(4) const u8 sText_RandomChatMale2[] = _("¿Ah si?\n¿Eso es lo que dices?\p");
ALIGNED(4) const u8 sText_LearnedSomethingFemale[] = _("¿De verdad?\nNo lo conocía.\p");
ALIGNED(4) const u8 sText_ThatsFunnyFemale[] = _("¡Jajaja!\n¿De verdad?\p");
ALIGNED(4) const u8 sText_RandomChatFemale1[] = _("¡Exacto!\nEso estaba diciendo.\p");
ALIGNED(4) const u8 sText_RandomChatFemale2[] = _("En otras palabras…\n¡Meowth! ¡Asi és!\p");

const u8 *const sChatReactionTexts[GENDER_COUNT][4] = {
    {
        sText_LearnedSomethingMale,
        sText_ThatsFunnyMale,
        sText_RandomChatMale1,
        sText_RandomChatMale2
    }, 
    {
        sText_LearnedSomethingFemale,
        sText_ThatsFunnyFemale,
        sText_RandomChatFemale1,
        sText_RandomChatFemale2
    }
};

ALIGNED(4) const u8 sText_ShowedTrainerCardMale1[] = _("Te muestro mi FICHA ENTRENADOR\na modo introductorio.\p");
ALIGNED(4) const u8 sText_ShowedTrainerCardMale2[] = _("¡Espero conocerte mejor!\p");
ALIGNED(4) const u8 sText_ShowedTrainerCardFemale1[] = _("Veamos nuestras\nFICHAS ENTRENADOR para conocernos.\p");
ALIGNED(4) const u8 sText_ShowedTrainerCardFemale2[] = _("Un placer conocerte.\n¡Forjemos una linda amistad!\p");

const u8 *const sTrainerCardReactionTexts[GENDER_COUNT][2] = {
    {
        sText_ShowedTrainerCardMale1,
        sText_ShowedTrainerCardMale2
    }, 
    {
        sText_ShowedTrainerCardFemale1,
        sText_ShowedTrainerCardFemale2
    }
};

ALIGNED(4) const u8 sText_MaleTraded1[] = _("¡Oh si!\n¡De verdad quería este POKéMON!\p");
ALIGNED(4) const u8 sText_MaleTraded2[] = _("¡Al fin! el intercambio me dio\nel POKéMON que buscaba hace mucho.\p");
ALIGNED(4) const u8 sText_FemaleTraded1[] = _("Estoy intercambiando POKéMON justo ahora.\p");
ALIGNED(4) const u8 sText_FemaleTraded2[] = _("¡El fin conseguí al POKéMON que\nquería en un intercambio!\p");

const u8 *const sTradeReactionTexts[GENDER_COUNT][4] = {
    {
        sText_MaleTraded1,
        sText_MaleTraded2
    }, 
    {
        sText_FemaleTraded1,
        sText_FemaleTraded2
    }
};

ALIGNED(4) const u8 sText_XCheckedTradingBoard[] = _("{STR_VAR_1} revisó\nla FICHA ENTRENADOR.\p");
ALIGNED(4) const u8 sText_RegisterMonAtTradingBoard[] = _("Bienvenido al tablón.\pAqui puedes registrar tus POKéMON\npara ofrecerlos como intercambio.\p¿Quieres registrar alguno de\ntus POKéMON?");
ALIGNED(4) const u8 sText_TradingBoardInfo[] = _("Este tablón se utiliza\npara ofrecer POKéMON como intercambio.\pSolo debes seleccionar un\nPOKéMON que quieras intercambiar.\pOtro entrenador podrá luego ofrecer\nun POKéMON de su equipo como oferta.\pEsperemos que registres muchos POKéMON\ne intercambies con muchos otros\lEntrenadores.\p¿Quíeres registrar\nalgún POKéMON?");
ALIGNED(4) const u8 sText_ThankYouForRegistering[] = _("We have registered your POKéMON for\ntrade on the TRADING BOARD.\pThank you for using this service!\p"); // unused
ALIGNED(4) const u8 sText_NobodyHasRegistered[] = _("Nobody has registered any POKéMON\nfor trade on the TRADING BOARD.\p\n"); // unused
ALIGNED(4) const u8 sText_ChooseRequestedMonType[] = _("Elige el tipo del POKéMON\nque deseas recibir como intercambio.\n");
ALIGNED(4) const u8 sText_WhichMonWillYouOffer[] = _("¿Cúal POKéMON de tu equipo\nofreces a cambio?\p");
ALIGNED(4) const u8 sText_RegistrationCanceled[] = _("Se canceló el registro.\p");
ALIGNED(4) const u8 sText_RegistraionCompleted[] = _("Se completó el registro.\p");
ALIGNED(4) const u8 sText_TradeCanceled[] = _("The trade has been canceled.\p");
ALIGNED(4) const u8 sText_CancelRegistrationOfMon[] = _("¿Cancelas el registro de tu\n {STR_VAR_1} Nv. {STR_VAR_2}?");
ALIGNED(4) const u8 sText_CancelRegistrationOfEgg[] = _("¿Cancelas el registro\ndel Huevo?");
ALIGNED(4) const u8 sText_RegistrationCanceled2[] = _("Se canceló el registro.\p");
ALIGNED(4) const u8 sText_TradeTrainersWillBeListed[] = _("TRAINERS wishing to make a trade\nwill be listed."); // unused
ALIGNED(4) const u8 sText_ChooseTrainerToTradeWith2[] = _("Please choose the TRAINER with whom\nyou would like to trade POKéMON."); // unused
ALIGNED(4) const u8 sText_AskTrainerToMakeTrade[] = _("¿Quieres realizar un intercambio con\n{STR_VAR_1}?");
ALIGNED(4) const u8 sText_AwaitingResponseFromTrainer2[] = _("Awaiting a response from\nthe other TRAINER…"); // unused
ALIGNED(4) const u8 sText_NotRegisteredAMonForTrade[] = _("You have not registered a POKéMON\nfor trading.\p"); // unused
ALIGNED(4) const u8 sText_DontHaveTypeTrainerWants[] = _("No tienes un POKéMON tipo {STR_VAR_2}\nque {STR_VAR_1} pide a cambio.\p");
ALIGNED(4) const u8 sText_DontHaveEggTrainerWants[] = _("No tienes un Huevo que\n{STR_VAR_1} pide a cambio.\p");
ALIGNED(4) const u8 sText_PlayerCantTradeForYourMon[] = _("{STR_VAR_1} no puede intercambiar\ncontigo en este momento.\p");
ALIGNED(4) const u8 sText_CantTradeForPartnersMon[] = _("No puedes intercambiar con\n{STR_VAR_1} en este momento.\p");

// Unused
const u8 *const sCantTradeMonTexts[] = {
    sText_PlayerCantTradeForYourMon,
    sText_CantTradeForPartnersMon
};

ALIGNED(4) const u8 sText_TradeOfferRejected[] = _("Se rechazó el intercambio.\p");
ALIGNED(4) const u8 sText_EggTrade[] = _("INTERCAMBIO HUEVO");
ALIGNED(4) const u8 sText_ChooseJoinCancel[] = _("{DPAD_UPDOWN}Elegir  {A_BUTTON}Unirse  {B_BUTTON}Salir");
ALIGNED(4) const u8 sText_ChooseTrainer[] = _("Elige un Entrenador.");
ALIGNED(4) const u8 sText_ChooseTrainerSingleBattle[] = _("Elige un entrenador para\nuna Batalla Simple.");
ALIGNED(4) const u8 sText_ChooseTrainerDoubleBattle[] = _("Elige un entrenador para\nuna Batalla Doble.");
ALIGNED(4) const u8 sText_ChooseLeaderMultiBattle[] = _("Elige el Líder de\nla Batalla Múltiple.");
ALIGNED(4) const u8 sText_ChooseTrainerToTradeWith[] = _("Elige un entrenador para\nintercambiar contigo.");
ALIGNED(4) const u8 sText_ChooseTrainerToShareWonderCards[] = _("Elige el entrenador que comparte\nFICHAS.");
ALIGNED(4) const u8 sText_ChooseTrainerToShareWonderNews[] = _("Elige el interenador que comparte\nNOTICIAS.");
ALIGNED(4) const u8 sText_ChooseLeaderPokemonJump[] = _("¡Salta con pequeños POKéMON!\nElige al Líder.");
ALIGNED(4) const u8 sText_ChooseLeaderBerryCrush[] = _("¡Machacabayas!\nElige al Líder.");
ALIGNED(4) const u8 sText_ChooseLeaderBerryPicking[] = _("¡DODRIO Recogebayas!\nElige al Lider.");
ALIGNED(4) const u8 sText_ChooseLeaderBerryBlender[] = _("¡Licuabayas!\nElige al Lider.");
ALIGNED(4) const u8 sText_ChooseLeaderRecordCorner[] = _("¡Mezcla de Registros!\nElige al Lider.");
ALIGNED(4) const u8 sText_ChooseLeaderCoolContest[] = _("¡Concurso de Carisma!\nElige al Lider.");
ALIGNED(4) const u8 sText_ChooseLeaderBeautyContest[] = _("¡Concurso de Belleza!\nElige al Lider.");
ALIGNED(4) const u8 sText_ChooseLeaderCuteContest[] = _("¡Concurso de Dulzura!\nElige al Lider.");
ALIGNED(4) const u8 sText_ChooseLeaderSmartContest[] = _("¡Concurso de Ingenio!\nElige al Lider.");
ALIGNED(4) const u8 sText_ChooseLeaderToughContest[] = _("¡Concurso de Dureza!\nElige al Lider.");
ALIGNED(4) const u8 sText_ChooseLeaderBattleTowerLv50[] = _("¡Torre Batlla Nv 50!\nElige al Lider.");
ALIGNED(4) const u8 sText_ChooseLeaderBattleTowerOpenLv[] = _("¡Torre Batlla Nv Libre!\nElige al Lider.");

static const u8 *const sChooseTrainerTexts[NUM_LINK_GROUP_TYPES] = 
{
    [LINK_GROUP_SINGLE_BATTLE]     = sText_ChooseTrainerSingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE]     = sText_ChooseTrainerDoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]      = sText_ChooseLeaderMultiBattle,
    [LINK_GROUP_TRADE]             = sText_ChooseTrainerToTradeWith,
    [LINK_GROUP_POKEMON_JUMP]      = sText_ChooseLeaderPokemonJump,
    [LINK_GROUP_BERRY_CRUSH]       = sText_ChooseLeaderBerryCrush,
    [LINK_GROUP_BERRY_PICKING]     = sText_ChooseLeaderBerryPicking,
    [LINK_GROUP_WONDER_CARD]       = sText_ChooseTrainerToShareWonderCards,
    [LINK_GROUP_WONDER_NEWS]       = sText_ChooseTrainerToShareWonderNews,
    [LINK_GROUP_UNION_ROOM_RESUME] = NULL,
    [LINK_GROUP_UNION_ROOM_INIT]   = NULL,
    [LINK_GROUP_UNK_11]            = NULL,
    [LINK_GROUP_RECORD_CORNER]     = sText_ChooseLeaderRecordCorner,
    [LINK_GROUP_BERRY_BLENDER]     = sText_ChooseLeaderBerryBlender,
    [LINK_GROUP_UNK_14]            = NULL,
    [LINK_GROUP_COOL_CONTEST]      = sText_ChooseLeaderCoolContest,
    [LINK_GROUP_BEAUTY_CONTEST]    = sText_ChooseLeaderBeautyContest,
    [LINK_GROUP_CUTE_CONTEST]      = sText_ChooseLeaderCuteContest,
    [LINK_GROUP_SMART_CONTEST]     = sText_ChooseLeaderSmartContest,
    [LINK_GROUP_TOUGH_CONTEST]     = sText_ChooseLeaderToughContest,
    [LINK_GROUP_BATTLE_TOWER]      = sText_ChooseLeaderBattleTowerLv50,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sText_ChooseLeaderBattleTowerOpenLv
};

ALIGNED(4) const u8 sText_SearchingForWirelessSystemWait[] = _("Buscando\nconexiones inalámbricas. Espere...");
ALIGNED(4) const u8 sText_MustHaveTwoMonsForDoubleBattle[] = _("For a DOUBLE BATTLE, you must have\nat least two POKéMON.\p"); // Unused
ALIGNED(4) const u8 sText_AwaitingPlayersResponse[] = _("Esperando respuesta de {STR_VAR_1}…");
ALIGNED(4) const u8 sText_PlayerHasBeenAskedToRegisterYouPleaseWait[] = _("{STR_VAR_1} solicitú tu registro\ncomo miembro. Espere por favor.");
ALIGNED(4) const u8 sText_AwaitingResponseFromWirelessSystem[] = _("Esperando respuesta del\nsistema de comunicación inalámbrica.");
ALIGNED(4) const u8 sText_PleaseWaitForOtherTrainersToGather[] = _("Please wait for other TRAINERS to\ngather and get ready."); // Unused
ALIGNED(4) const u8 sText_NoCardsSharedRightNow[] = _("No se comparten FICHAS\nen este momento.");
ALIGNED(4) const u8 sText_NoNewsSharedRightNow[] = _("No se comparten noticias\nen este momento.");

const u8 *const sNoWonderSharedTexts[] = {
    sText_NoCardsSharedRightNow,
    sText_NoNewsSharedRightNow
};

ALIGNED(4) const u8 sText_Battle[] = _("Luchar");
ALIGNED(4) const u8 sText_Chat2[] = _("Hablar");
ALIGNED(4) const u8 sText_Greetings[] = _("Saludos");
ALIGNED(4) const u8 sText_Exit[] = _("Salir");
ALIGNED(4) const u8 sText_Exit2[] = _("Salir");
ALIGNED(4) const u8 sText_Info[] = _("Datos");
ALIGNED(4) const u8 sText_NameWantedOfferLv[] = _("Nombre{CLEAR_TO 0x3C}Quiere{CLEAR_TO 0x6E}Ofrece{CLEAR_TO 0xC6}Nv.");
ALIGNED(4) const u8 sText_SingleBattle[] = _("Batalla Simple");
ALIGNED(4) const u8 sText_DoubleBattle[] = _("Batalla Doble");
ALIGNED(4) const u8 sText_MultiBattle[] = _("Batalla Múltiple");
ALIGNED(4) const u8 sText_PokemonTrades[] = _("Intercambios");
ALIGNED(4) const u8 sText_Chat[] = _("Hablar");
ALIGNED(4) const u8 sText_Cards[] = _("Fichas");
ALIGNED(4) const u8 sText_WonderCards[] = _("Fichas");
ALIGNED(4) const u8 sText_WonderNews[] = _("Noticias");
ALIGNED(4) const u8 sText_PokemonJump[] = _("Salto POKéMON");
ALIGNED(4) const u8 sText_BerryCrush[] = _("Machacabayas");
ALIGNED(4) const u8 sText_BerryPicking[] = _("Recogebayas");
ALIGNED(4) const u8 sText_Search[] = _("Buscar");
ALIGNED(4) const u8 sText_BerryBlender[] = _("Licuabayas");
ALIGNED(4) const u8 sText_RecordCorner[] = _("Mezclar registros");
ALIGNED(4) const u8 sText_CoolContest[] = _("Concurso de Carisma");
ALIGNED(4) const u8 sText_BeautyContest[] = _("Concurso de Belleza");
ALIGNED(4) const u8 sText_CuteContest[] = _("Concurso de Dulzura");
ALIGNED(4) const u8 sText_SmartContest[] = _("Concurso de Ingenio");
ALIGNED(4) const u8 sText_ToughContest[] = _("Concurso de Dureza");
ALIGNED(4) const u8 sText_BattleTowerLv50[] = _("Torre Batalla Nv. 50");
ALIGNED(4) const u8 sText_BattleTowerOpenLv[] = _("Torre Batalla Nv. Libre");
ALIGNED(4) const u8 sText_ItsNormalCard[] = _("Es una Ficha normal.");
ALIGNED(4) const u8 sText_ItsBronzeCard[] = _("¡Es una ficha de bronze!");
ALIGNED(4) const u8 sText_ItsCopperCard[] = _("¡Es una ficha de cobre!");
ALIGNED(4) const u8 sText_ItsSilverCard[] = _("¡Es una ficha plateada!");
ALIGNED(4) const u8 sText_ItsGoldCard[] = _("¡Es una ficha dorada!");

static const u8 *const sCardColorTexts[] = {
    sText_ItsNormalCard,
    sText_ItsBronzeCard,
    sText_ItsCopperCard,
    sText_ItsSilverCard,
    sText_ItsGoldCard
};

ALIGNED(4) const u8 sText_TrainerCardInfoPage1[] = _("Esta es La FICHA ENTRENADOR de \n{DYNAMIC 0} {DYNAMIC 1}…\l{DYNAMIC 2}\pPOKéDEX: {DYNAMIC 3}\nT. Juego:    {DYNAMIC 4}:{DYNAMIC 5}\p");
ALIGNED(4) const u8 sText_TrainerCardInfoPage2[] = _("Batallas: V: {DYNAMIC 0}  D: {DYNAMIC 2}\nIntercambios: {DYNAMIC 3}\p“{DYNAMIC 4} {DYNAMIC 5}\n{DYNAMIC 6} {DYNAMIC 7}”\p");
ALIGNED(4) const u8 sText_GladToMeetYouMale[] = _("{DYNAMIC 1}: ¡Un placer conocerte!{PAUSE 60}");
ALIGNED(4) const u8 sText_GladToMeetYouFemale[] = _("{DYNAMIC 1}: ¡Un placer conocerte!{PAUSE 60}");

const u8 *const sGladToMeetYouTexts[GENDER_COUNT] = {
    sText_GladToMeetYouMale,
    sText_GladToMeetYouFemale
};

ALIGNED(4) const u8 sText_FinishedCheckingPlayersTrainerCard[] = _("Terminaste de revisar la FICHA ENTRENADOR de\n{DYNAMIC 1}.{PAUSE 60}");

static const u8 *const sLinkGroupActivityNameTexts[] = {
    [ACTIVITY_NONE]              = sText_EmptyString,
    [ACTIVITY_BATTLE_SINGLE]     = sText_SingleBattle,
    [ACTIVITY_BATTLE_DOUBLE]     = sText_DoubleBattle,
    [ACTIVITY_BATTLE_MULTI]      = sText_MultiBattle,
    [ACTIVITY_TRADE]             = sText_PokemonTrades,
    [ACTIVITY_CHAT]              = sText_Chat,
    [ACTIVITY_WONDER_CARD]       = sText_WonderCards,
    [ACTIVITY_WONDER_NEWS]       = sText_WonderNews,
    [ACTIVITY_CARD]              = sText_Cards,
    [ACTIVITY_POKEMON_JUMP]      = sText_PokemonJump,
    [ACTIVITY_BERRY_CRUSH]       = sText_BerryCrush,
    [ACTIVITY_BERRY_PICK]        = sText_BerryPicking,
    [ACTIVITY_SEARCH]            = sText_Search,
    [ACTIVITY_SPIN_TRADE]        = sText_EmptyString,
    [ACTIVITY_BATTLE_TOWER_OPEN] = sText_BattleTowerOpenLv,
    [ACTIVITY_RECORD_CORNER]     = sText_RecordCorner,
    [ACTIVITY_BERRY_BLENDER]     = sText_BerryBlender,
    [ACTIVITY_ACCEPT]            = sText_EmptyString,
    [ACTIVITY_DECLINE]           = sText_EmptyString,
    [ACTIVITY_NPCTALK]           = sText_EmptyString,
    [ACTIVITY_PLYRTALK]          = sText_EmptyString,
    [ACTIVITY_WONDER_CARD2]      = sText_WonderCards,
    [ACTIVITY_WONDER_NEWS2]      = sText_WonderNews,
    [ACTIVITY_CONTEST_COOL]      = sText_CoolContest,
    [ACTIVITY_CONTEST_BEAUTY]    = sText_BeautyContest,
    [ACTIVITY_CONTEST_CUTE]      = sText_CuteContest,
    [ACTIVITY_CONTEST_SMART]     = sText_SmartContest,
    [ACTIVITY_CONTEST_TOUGH]     = sText_ToughContest,
    [ACTIVITY_BATTLE_TOWER]      = sText_BattleTowerLv50
};

static const struct WindowTemplate sWindowTemplate_BButtonCancel = {
    .bg = 0x00,
    .tilemapLeft = 0x00,
    .tilemapTop = 0x00,
    .width = 0x1E,
    .height = 0x02,
    .paletteNum = 0x0F,
    .baseBlock = 0x0008
};

// Minimum and maximum number of players for a link group
// A minimum of 0 means the min and max are equal
#define LINK_GROUP_CAPACITY(min, max)(((min) << 12) | ((max) << 8))
#define GROUP_MAX(capacity)(capacity & 0x0F)
#define GROUP_MIN(capacity)(capacity >> 4)
#define GROUP_MIN2(capacity)(capacity & 0xF0) // Unnecessary to have both, but needed to match

static const u32 sLinkGroupToActivityAndCapacity[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = ACTIVITY_BATTLE_SINGLE     | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_DOUBLE_BATTLE]     = ACTIVITY_BATTLE_DOUBLE     | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_MULTI_BATTLE]      = ACTIVITY_BATTLE_MULTI      | LINK_GROUP_CAPACITY(0, 4),
    [LINK_GROUP_TRADE]             = ACTIVITY_TRADE             | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_POKEMON_JUMP]      = ACTIVITY_POKEMON_JUMP      | LINK_GROUP_CAPACITY(2, 5),
    [LINK_GROUP_BERRY_CRUSH]       = ACTIVITY_BERRY_CRUSH       | LINK_GROUP_CAPACITY(2, 5),
    [LINK_GROUP_BERRY_PICKING]     = ACTIVITY_BERRY_PICK        | LINK_GROUP_CAPACITY(3, 5),
    [LINK_GROUP_WONDER_CARD]       = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_WONDER_NEWS]       = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNION_ROOM_RESUME] = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNION_ROOM_INIT]   = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNK_11]            = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_RECORD_CORNER]     = ACTIVITY_RECORD_CORNER     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BERRY_BLENDER]     = ACTIVITY_BERRY_BLENDER     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_UNK_14]            = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_COOL_CONTEST]      = ACTIVITY_CONTEST_COOL      | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BEAUTY_CONTEST]    = ACTIVITY_CONTEST_BEAUTY    | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_CUTE_CONTEST]      = ACTIVITY_CONTEST_CUTE      | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_SMART_CONTEST]     = ACTIVITY_CONTEST_SMART     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_TOUGH_CONTEST]     = ACTIVITY_CONTEST_TOUGH     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BATTLE_TOWER]      = ACTIVITY_BATTLE_TOWER      | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_BATTLE_TOWER_OPEN] = ACTIVITY_BATTLE_TOWER_OPEN | LINK_GROUP_CAPACITY(0, 2)
};

static const struct WindowTemplate sWindowTemplate_PlayerList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 13,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_5PlayerList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 13,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_NumPlayerMode = {
    .bg = 0,
    .tilemapLeft = 16,
    .tilemapTop = 3,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x00c6
};

static const struct ListMenuItem sPossibleGroupMembersListMenuItems[] = {
    { sText_EmptyString, 0 },
    { sText_EmptyString, 1 },
    { sText_EmptyString, 2 },
    { sText_EmptyString, 3 },
    { sText_EmptyString, 4 }
};

static const struct ListMenuTemplate sListMenuTemplate_PossibleGroupMembers = {
    .items = sPossibleGroupMembersListMenuItems,
    .moveCursorFunc = NULL,
    .itemPrintFunc = ItemPrintFunc_PossibleGroupMembers,
    .totalItems = ARRAY_COUNT(sPossibleGroupMembersListMenuItems),
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 0,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 1
};

const struct WindowTemplate gUnknown_082F0174 = {
    .bg = 0x00,
    .tilemapLeft = 0x01,
    .tilemapTop = 0x03,
    .width = 0x11,
    .height = 0x0a,
    .paletteNum = 0x0f,
    .baseBlock = 0x0044
};

const struct WindowTemplate gUnknown_082F017C = {
    .bg = 0x00,
    .tilemapLeft = 0x14,
    .tilemapTop = 0x03,
    .width = 0x07,
    .height = 0x04,
    .paletteNum = 0x0f,
    .baseBlock = 0x00ee
};

const struct ListMenuItem gUnknown_082F0184[] = {
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_EmptyString,  8 },
    { sText_EmptyString,  9 },
    { sText_EmptyString, 10 },
    { sText_EmptyString, 11 },
    { sText_EmptyString, 12 },
    { sText_EmptyString, 13 },
    { sText_EmptyString, 14 },
    { sText_EmptyString, 15 }
};

static const struct ListMenuTemplate sListMenuTemplate_UnionRoomGroups = {
    .items = gUnknown_082F0184,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = ListMenuItemPrintFunc_UnionRoomGroups,
    .totalItems = ARRAY_COUNT(gUnknown_082F0184),
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 1,
    .fontId = 1,
    .cursorKind = 0
};

static const struct WindowTemplate sWindowTemplate_InviteToActivity = {
    .bg = 0x00,
    .tilemapLeft = 0x14,
    .tilemapTop = 0x05,
    .width = 0x10,
    .height = 0x08,
    .paletteNum = 0x0f,
    .baseBlock = 0x0001
};

const struct ListMenuItem gUnknown_082F0224[] = {
    { sText_Greetings, 0x208 },
    { sText_Battle, 0x241 },
    { sText_Chat2, 0x245 },
    { sText_Exit, 0x040 }
};

static const struct ListMenuTemplate sListMenuTemplate_InviteToActivity = {
    .items = gUnknown_082F0224,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(gUnknown_082F0224),
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 0
};

static const struct WindowTemplate sWindowTemplate_RegisterForTrade = {
    .bg = 0x00,
    .tilemapLeft = 0x12,
    .tilemapTop = 0x07,
    .width = 0x10,
    .height = 0x06,
    .paletteNum = 0x0f,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sRegisterForTradeListMenuItems[] = {
    { gText_Register, 1 },
    { sText_Info, 2 },
    { sText_Exit, 3 }
};

static const struct ListMenuTemplate sListMenuTemplate_RegisterForTrade = {
    .items = sRegisterForTradeListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sRegisterForTradeListMenuItems),
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 0
};

const struct WindowTemplate gUnknown_082F0294 = {
    .bg = 0x00,
    .tilemapLeft = 0x14,
    .tilemapTop = 0x01,
    .width = 0x10,
    .height = 0x0c,
    .paletteNum = 0x0f,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sTradingBoardTypes[NUMBER_OF_MON_TYPES] = {
    { gTypeNames[TYPE_NORMAL],   TYPE_NORMAL         },
    { gTypeNames[TYPE_FIRE],     TYPE_FIRE           },
    { gTypeNames[TYPE_WATER],    TYPE_WATER          },
    { gTypeNames[TYPE_ELECTRIC], TYPE_ELECTRIC       },
    { gTypeNames[TYPE_GRASS],    TYPE_GRASS          },
    { gTypeNames[TYPE_ICE],      TYPE_ICE            },
    { gTypeNames[TYPE_GROUND],   TYPE_GROUND         },
    { gTypeNames[TYPE_ROCK],     TYPE_ROCK           },
    { gTypeNames[TYPE_FLYING],   TYPE_FLYING         },
    { gTypeNames[TYPE_PSYCHIC],  TYPE_PSYCHIC        },
    { gTypeNames[TYPE_FIGHTING], TYPE_FIGHTING       },
    { gTypeNames[TYPE_POISON],   TYPE_POISON         },
    { gTypeNames[TYPE_BUG],      TYPE_BUG            },
    { gTypeNames[TYPE_GHOST],    TYPE_GHOST          },
    { gTypeNames[TYPE_DRAGON],   TYPE_DRAGON         },
    { gTypeNames[TYPE_STEEL],    TYPE_STEEL          },
    { gTypeNames[TYPE_DARK],     TYPE_DARK           },
    { sText_Exit,                NUMBER_OF_MON_TYPES }
};

static const struct ListMenuTemplate sMenuTemplate_TradingBoardRequestType = {
    .items = sTradingBoardTypes,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sTradingBoardTypes),
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 0
};

static const struct WindowTemplate sWindowTemplate_TradingBoard = {
    .bg = 0x00,
    .tilemapLeft = 0x01,
    .tilemapTop = 0x01,
    .width = 0x1c,
    .height = 0x02,
    .paletteNum = 0x0d,
    .baseBlock = 0x0001
};

const struct WindowTemplate gUnknown_082F034C = {
    .bg = 0x00,
    .tilemapLeft = 0x01,
    .tilemapTop = 0x05,
    .width = 0x1c,
    .height = 0x0c,
    .paletteNum = 0x0d,
    .baseBlock = 0x0039
};

static const struct ListMenuItem sTradeBoardListMenuItems[] = {
    { sText_EmptyString, -3 },
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_Exit2,  8 }
};

static const struct ListMenuTemplate sTradeBoardListMenuTemplate = {
    .items = sTradeBoardListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = TradeBoardListMenuItemPrintFunc,
    .totalItems = ARRAY_COUNT(sTradeBoardListMenuItems),
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 14,
    .fillValue = 15,
    .cursorShadowPal = 13,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 0
};

const struct WindowTemplate UnrefWindowTemplate_082F03B4 = {
    .bg = 0x00,
    .tilemapLeft = 0x01,
    .tilemapTop = 0x05,
    .width = 0x1c,
    .height = 0x0c,
    .paletteNum = 0x0d,
    .baseBlock = 0x0039
};

static const struct ListMenuItem sEmptyListMenuItems[] = {
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_EmptyString,  8 },
    { sText_EmptyString,  9 },
    { sText_EmptyString, 10 },
    { sText_EmptyString, 11 },
    { sText_EmptyString, 12 },
    { sText_EmptyString, 13 },
    { sText_EmptyString, 14 },
    { sText_EmptyString, 15 }
};

// Unused
static const struct ListMenuTemplate sUnknownListMenuTemplate = {
    .items = sEmptyListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = nullsub_14,
    .totalItems = ARRAY_COUNT(sEmptyListMenuItems),
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 1,
    .fontId = 1,
    .cursorKind = 0
};

const struct WirelessGnameUnamePair sWirelessGnameUnamePair_Dummy = {0};

ALIGNED(4) const u8 sAcceptedActivityIds_SingleBattle[]    = {ACTIVITY_BATTLE_SINGLE, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_DoubleBattle[]    = {ACTIVITY_BATTLE_DOUBLE, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_MultiBattle[]     = {ACTIVITY_BATTLE_MULTI, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_Trade[]           = {ACTIVITY_TRADE, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_PokemonJump[]     = {ACTIVITY_POKEMON_JUMP, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_BerryCrush[]      = {ACTIVITY_BERRY_CRUSH, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_BerryPicking[]    = {ACTIVITY_BERRY_PICK, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_WonderCard[]      = {ACTIVITY_WONDER_CARD2, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_WonderNews[]      = {ACTIVITY_WONDER_NEWS2, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_Resume[]          = {
    IN_UNION_ROOM | ACTIVITY_NONE, 
    IN_UNION_ROOM | ACTIVITY_BATTLE_SINGLE, 
    IN_UNION_ROOM | ACTIVITY_TRADE, 
    IN_UNION_ROOM | ACTIVITY_CHAT, 
    IN_UNION_ROOM | ACTIVITY_CARD, 
    IN_UNION_ROOM | ACTIVITY_ACCEPT, 
    IN_UNION_ROOM | ACTIVITY_DECLINE, 
    IN_UNION_ROOM | ACTIVITY_NPCTALK, 
    IN_UNION_ROOM | ACTIVITY_PLYRTALK, 
    0xff
};
ALIGNED(4) const u8 sAcceptedActivityIds_Init[]            = {ACTIVITY_SEARCH, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_Unk11[]           = {
    ACTIVITY_BATTLE_SINGLE, 
    ACTIVITY_BATTLE_DOUBLE, 
    ACTIVITY_BATTLE_MULTI, 
    ACTIVITY_TRADE, 
    ACTIVITY_POKEMON_JUMP, 
    ACTIVITY_BERRY_CRUSH, 
    ACTIVITY_BERRY_PICK, 
    ACTIVITY_WONDER_CARD2, 
    ACTIVITY_WONDER_NEWS2, 
    ACTIVITY_SPIN_TRADE, 
    0xff
};
ALIGNED(4) const u8 sAcceptedActivityIds_RecordCorner[]    = {ACTIVITY_RECORD_CORNER, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_BerryBlender[]    = {ACTIVITY_BERRY_BLENDER, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_CoolContest[]     = {ACTIVITY_CONTEST_COOL, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_BeautyContest[]   = {ACTIVITY_CONTEST_BEAUTY, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_CuteContest[]     = {ACTIVITY_CONTEST_CUTE, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_SmartContest[]    = {ACTIVITY_CONTEST_SMART, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_ToughContest[]    = {ACTIVITY_CONTEST_TOUGH, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_BattleTower[]     = {ACTIVITY_BATTLE_TOWER, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_BattleTowerOpen[] = {ACTIVITY_BATTLE_TOWER_OPEN, 0xff};

const u8 *const sAcceptedActivityIds[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = sAcceptedActivityIds_SingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE]     = sAcceptedActivityIds_DoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]      = sAcceptedActivityIds_MultiBattle,
    [LINK_GROUP_TRADE]             = sAcceptedActivityIds_Trade,
    [LINK_GROUP_POKEMON_JUMP]      = sAcceptedActivityIds_PokemonJump,
    [LINK_GROUP_BERRY_CRUSH]       = sAcceptedActivityIds_BerryCrush,
    [LINK_GROUP_BERRY_PICKING]     = sAcceptedActivityIds_BerryPicking,
    [LINK_GROUP_WONDER_CARD]       = sAcceptedActivityIds_WonderCard,
    [LINK_GROUP_WONDER_NEWS]       = sAcceptedActivityIds_WonderNews,
    [LINK_GROUP_UNION_ROOM_RESUME] = sAcceptedActivityIds_Resume,
    [LINK_GROUP_UNION_ROOM_INIT]   = sAcceptedActivityIds_Init,
    [LINK_GROUP_UNK_11]            = sAcceptedActivityIds_Unk11,
    [LINK_GROUP_RECORD_CORNER]     = sAcceptedActivityIds_RecordCorner,
    [LINK_GROUP_BERRY_BLENDER]     = sAcceptedActivityIds_BerryBlender,
    [LINK_GROUP_UNK_14]            = NULL,
    [LINK_GROUP_COOL_CONTEST]      = sAcceptedActivityIds_CoolContest,
    [LINK_GROUP_BEAUTY_CONTEST]    = sAcceptedActivityIds_BeautyContest,
    [LINK_GROUP_CUTE_CONTEST]      = sAcceptedActivityIds_CuteContest,
    [LINK_GROUP_SMART_CONTEST]     = sAcceptedActivityIds_SmartContest,
    [LINK_GROUP_TOUGH_CONTEST]     = sAcceptedActivityIds_ToughContest,
    [LINK_GROUP_BATTLE_TOWER]      = sAcceptedActivityIds_BattleTower,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sAcceptedActivityIds_BattleTowerOpen
};

static const u8 sLinkGroupToURoomActivity[NUM_LINK_GROUP_TYPES + 2] = 
{
    [LINK_GROUP_SINGLE_BATTLE]     = ACTIVITY_BATTLE_SINGLE, 
    [LINK_GROUP_DOUBLE_BATTLE]     = ACTIVITY_BATTLE_DOUBLE, 
    [LINK_GROUP_MULTI_BATTLE]      = ACTIVITY_BATTLE_MULTI, 
    [LINK_GROUP_TRADE]             = ACTIVITY_TRADE, 
    [LINK_GROUP_POKEMON_JUMP]      = ACTIVITY_POKEMON_JUMP, 
    [LINK_GROUP_BERRY_CRUSH]       = ACTIVITY_BERRY_CRUSH, 
    [LINK_GROUP_BERRY_PICKING]     = ACTIVITY_BERRY_PICK, 
    [LINK_GROUP_WONDER_CARD]       = ACTIVITY_WONDER_CARD2,
    [LINK_GROUP_WONDER_NEWS]       = ACTIVITY_WONDER_NEWS2, 
    [LINK_GROUP_UNION_ROOM_RESUME] = ACTIVITY_NONE, 
    [LINK_GROUP_UNION_ROOM_INIT]   = ACTIVITY_NONE, 
    [LINK_GROUP_UNK_11]            = ACTIVITY_NONE, 
    [LINK_GROUP_RECORD_CORNER]     = ACTIVITY_RECORD_CORNER, 
    [LINK_GROUP_BERRY_BLENDER]     = ACTIVITY_BERRY_BLENDER, 
    [LINK_GROUP_UNK_14]            = ACTIVITY_NONE, 
    [LINK_GROUP_COOL_CONTEST]      = ACTIVITY_CONTEST_COOL,
    [LINK_GROUP_BEAUTY_CONTEST]    = ACTIVITY_CONTEST_BEAUTY, 
    [LINK_GROUP_CUTE_CONTEST]      = ACTIVITY_CONTEST_CUTE, 
    [LINK_GROUP_SMART_CONTEST]     = ACTIVITY_CONTEST_SMART, 
    [LINK_GROUP_TOUGH_CONTEST]     = ACTIVITY_CONTEST_TOUGH, 
    [LINK_GROUP_BATTLE_TOWER]      = ACTIVITY_BATTLE_TOWER, 
    [LINK_GROUP_BATTLE_TOWER_OPEN] = ACTIVITY_BATTLE_TOWER_OPEN
};
