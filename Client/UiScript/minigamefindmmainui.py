import uiScriptLocale
import app

ROOT_PATH		= "d:/ymir work/ui/minigame/findm/"
WINDOW_WIDTH	= 456
WINDOW_HEIGHT	= 338

window = {
	"name" : "MiniGameFindMMainUI",
	"style" : ("movable", "float",),

	"x" : SCREEN_WIDTH / 2 - WINDOW_WIDTH / 2,
	"y" : SCREEN_HEIGHT / 2 - WINDOW_HEIGHT / 2,

	"width" : WINDOW_WIDTH,
	"height" : WINDOW_HEIGHT,

	"children" :
	[
		# Title bar
		{
			"name" : "board",
			"type" : "board_with_titlebar",

			"x" : 0,
			"y" : 0,

			"width" : WINDOW_WIDTH,
			"height" : WINDOW_HEIGHT,

			"title" : uiScriptLocale.MINI_GAME_FINDM_TITLE,
		},
		# Main BG
		{
			"name" : "main_bg",
			"type" : "image",

			"style" : ("ltr",),
			"x" : 10,
			"y" : 32,

			"image" : ROOT_PATH + "main_bg.sub",

			"children" :
			[
				# Time
				{
					"name" : "time_window",
					"type" : "window",

					"x" : 169,
					"y" : 9,

					"width" : 98,
					"height" : 21,

					"children" :
					[
						{
							"name" : "time",
							"type" : "text",

							"x" : 0,
							"y" : 0,

							"text" : "00:00",
							"all_align" : "center",
						},
					],
				}
			],
		},
		# Count down
		{
			"name" : "count_down_window",
			"type" : "window",

			"x" : 203,
			"y" : 306,

			"width" : 55,
			"height" : 18,

			"children" :
			[
				{
					"name" : "count_down_desc",
					"type" : "image",

					"x" : 0,
					"y" : 0,

					"image" : "d:/ymir work/ui/pattern/q_mark_02.tga",
				},
				{
					"name" : "count_down_image",
					"type" : "image",

					"x" : 20,
					"y" : 0,

					"image" : ROOT_PATH + "try_count.sub",

					"children" :
					[
						{
							"name" : "count_down",
							"type" : "text",

							"x" : 0,
							"y" : 0,

							"text" : "00",
							"all_align" : "center",
						},
					],
				},
			],
		},
		# Number of attempts
		{
			"name" : "try_count_window",
			"type" : "window",

			"x" : 349,
			"y" : 306,

			"width" : 55,
			"height" : 18,

			"children" :
			[
				{
					"name" : "try_count_title",
					"type" : "text",

					"x" : 2,
					"y" : 0,

					"text" : uiScriptLocale.MINI_GAME_FINDM_TRY_COUNT_TEXT,

					"vertical_align" : "center",
					"horizontal_align" : "right",
					"text_vertical_align" : "center",
					"text_horizontal_align" : "right",
				},
				{
					"name" : "try_count_image",
					"type" : "image",

					"x" : 57,
					"y" : 0,

					"image" : ROOT_PATH + "try_count.sub",

					"children" :
					[
						{
							"name" : "try_count",
							"type" : "text",

							"x" : 4,
							"y" : 0,

							"text" : "0",

							"vertical_align" : "center",
							"horizontal_align" : "right",
							"text_vertical_align" : "center",
							"text_horizontal_align" : "right",
						},
					],
				},
			],
		},
		# minigamefindmupgrade.py
		{
			"name" : "BoardUpgrade", #Board
			"type" : "board",

			"style" : ("float",),

			"vertical_align" : "center",
			"horizontal_align" : "center",

			"x" : 0,
			"y" : 0,

			"width" : 240,
			"height" : 180,

			"children" :
			[
				# Title Bar
				{
					"name" : "UpgradeTitleBar", #TitleBar
					"type" : "titlebar",

					"x" : 8,
					"y" : 7,

					"width" : 240 - 16,
					"color" : "red",

					#"title" : uiScriptLocale.LUCKY_BOX_TITLE_NAME,
					"children" :
					[
						{
							"name" : "TitleName",
							"type" : "text",

							"x" : 0,
							"y" : 0,

							"text" : uiScriptLocale.MINI_GAME_FINDM_UPGRADE_TITLE,
							"all_align" : "center",
						},
					],
				},
				# Item Bar
				{
					"name" : "RewardBar",
					"type" : "horizontalbar",

					"x" : 10,
					"y" : 40,

					"width" : 240 - 20,

					"children" :
					[
						{
							"name" : "RewardBarName",
							"type" : "text",

							"x" : 5,
							"y" : 2,

							"text" : uiScriptLocale.MINI_GAME_FINDM_UPGRADE_BAR1,
						},
					]
				},
				# Item Slot
				{
					"name" : "RewardItemSlot",
					"type" : "slot",

					"x" : 15,
					"y" : 70,

					"width" : 32,
					"height" : 32,

					"image" : "d:/ymir work/ui/public/Slot_Base.sub",

					"slot" :
					[
						{ "index" : 0, "x" : 0, "y" : 0, "width" : 32, "height" : 32, },
					],
				},
				# Get Button
				{
					"name" : "GetButton",
					"type" : "button",

					"x" : 51,
					"y" : 63,

					"text" : uiScriptLocale.MINI_GAME_FINDM_UPGRADE_RECV,

					"default_image"	: "d:/ymir work/ui/event/long_button_01.sub",
					"over_image"	: "d:/ymir work/ui/event/long_button_02.sub",
					"down_image"	: "d:/ymir work/ui/event/long_button_03.sub",
				},
				# Upgrade Button
				{
					"name" : "UpgradeButton",
					"type" : "button",

					"x" : 51,
					"y" : 89,

					"text" : uiScriptLocale.MINI_GAME_FINDM_UPGRADE_RETRY,
					"default_image"	: "d:/ymir work/ui/event/long_button_01.sub",
					"over_image"	: "d:/ymir work/ui/event/long_button_02.sub",
					"down_image"	: "d:/ymir work/ui/event/long_button_03.sub",
				},
				# NeedMoney Bar
				{
					"name" : "NeedMoneyBar",
					"type" : "horizontalbar",

					"x" : 10,
					"y" : 121,

					"width" : 240 - 20,

					"children" :
					[
						{
							"name" : "NeedMoneyBarName",
							"type" : "text",

							"x" : 5,
							"y" : 2,

							"text" : uiScriptLocale.MINI_GAME_FINDM_UPGRADE_BAR2,
						},
					]
				},
				# NeedMoney
				{
					"name" : "NeedMoneySlot",
					"type" : "expanded_image",

					"x" : 52,
					"y" : 145,

					"x_scale" : 1.92,
					"y_scale" : 1.0,

					"image" : "d:/ymir work/ui/public/gold_slot.sub",

					"children" :
					[
						{
							"name" : "NeedMoney",
							"type" : "text",

							"x" : 5,
							"y" : 0,

							"text" : "0",
							"vertical_align" : "center",
							"horizontal_align" : "right",
							"text_vertical_align" : "center",
							"text_horizontal_align" : "right",
						},
					],
				},
			],
		},
	],
}

if app.ENABLE_MINI_GAME_FINDM_HINT:
	window["children"] = window["children"] + [
		# Hint
		{
			"name" : "hint",
			"type" : "button",

			"x" : 11,
			"y" : 303,

			"text" : uiScriptLocale.MINI_GAME_FINDM_HINT_BTN,

			"default_image"	: ROOT_PATH + "hint_button_01.sub",
			"over_image"	: ROOT_PATH + "hint_button_02.sub",
			"down_image"	: ROOT_PATH + "hint_button_03.sub",
		},
		# Number of hints
		{
			"name" : "hint_count_image",
			"type" : "image",

			"style" : ("ltr",),

			"x" : 104,
			"y" : 304,

			"image" : ROOT_PATH + "hint_count.sub",

			"children" :
			[
				{
					"name" : "hint_count_text_window",
					"type" : "window",

					"x" : 22,
					"y" : 3,

					"width" : 34,
					"height" : 16,

					"children" :
					[
						{
							"name" : "hint_count",
							"type" : "text",

							"x" : 3,
							"y" : 0,

							"text" : "0",

							"vertical_align" : "center",
							"horizontal_align" : "right",
							"text_vertical_align" : "center",
							"text_horizontal_align" : "right",
						},
					],
				},
			],
		},]