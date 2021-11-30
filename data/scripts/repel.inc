EventScript_RepelWoreOff::
	msgbox Text_RepelWoreOff, MSGBOX_SIGN
	checkitem ITEM_REPEL, 1 
	goto_if_eq VAR_RESULT, TRUE, EventScript_RepelWoreOff_AskAnother
	checkitem ITEM_SUPER_REPEL, 1
	goto_if_eq VAR_RESULT, TRUE, EventScript_RepelWoreOff_AskAnother
	checkitem ITEM_MAX_REPEL, 1
	goto_if_eq VAR_RESULT, FALSE, EventScript_RepelWoreOff_End
EventScript_RepelWoreOff_AskAnother:
	msgbox Text_RepelAskAnother, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, 0, EventScript_RepelWoreOff_End
	callnative TryDrawRepelMenu
	goto_if_eq VAR_RESULT, FALSE, EventScript_RepelWoreOff_Chose
	waitstate
	goto_if_eq VAR_RESULT, 127, EventScript_RepelWoreOff_End
EventScript_RepelWoreOff_Chose:
	callnative HandleRepelMenuChoice
	bufferitemname 1, VAR_0x8004
	removeitem VAR_0x8004, 1
	playse SE_REPEL
	msgbox gText_PlayerUsedVar2, MSGBOX_SIGN
EventScript_RepelWoreOff_End:
	end

Text_RepelWoreOff:
	.string "REPEL's effect wore off…$"
Text_RepelAskAnother:
	.string "Would you like to use another one?$"
