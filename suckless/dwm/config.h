
static const unsigned int gappx	    = 20;
static const unsigned int borderpx  = 1;
static const unsigned int snap      = 1;
static const int swallowfloating    = 0;
static const int showbar            = 1;
static const int topbar             = 1;
static const char *fonts[]          = { "JetBrains Mono:size=10" };

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { "#f8f8f2", "#282a36", "#282a36" },
	[SchemeSel]  = { "#282a36", "#f8f8f2",  "#f8f8f2" },
};

static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };

static const Rule rules[] = {
	/* class     instance  title   tags_mask  isfloating  isterminal   noswallow   monitor */
    { "st",      NULL,     NULL,   0,         0,          1,           0,          -1 },
};

static const float mfact     = 0.5;
static const int nmaster     = 1;
static const int resizehints = 1;

static const Layout layouts[] = {
	{ "[T]",      tile },
	{ "[F]",      NULL },
	{ "[M]",      monocle },
    { "[C]",      centeredmaster },
};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static char dmenumon[2] = "0";
static const char *dmenucmd[]   = { "dmenu_run", NULL };
static const char *termcmd[]    = { "st", NULL };
static const char *browsercmd[] = { "librewolf", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_space,  spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_Left,   focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_Right,  focusstack,     {.i = +1 } },
    { MODKEY|ShiftMask,             XK_Left,   rotatestack,    {.i = -1 } },
    { MODKEY|ShiftMask,             XK_Right,  rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Up,     incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Down,   incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_Up,     setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_Down,   setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_k,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
    { MODKEY,                       XK_c,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ShiftMask,             XK_space,  setlayout,      {0} },
	{ MODKEY|Mod1Mask,              XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
    { MODKEY|Mod1Mask,              XK_Left,   setgaps,        {.i = -1 } },
    { MODKEY|Mod1Mask,              XK_Right,  setgaps,        {.i = +1 } },
	TAGKEYS(                        XK_1,                      0 )
	TAGKEYS(                        XK_2,                      1 )
	TAGKEYS(                        XK_3,                      2 )
	TAGKEYS(                        XK_4,                      3 )
	TAGKEYS(                        XK_5,                      4 )
	TAGKEYS(                        XK_6,                      5 )
	TAGKEYS(                        XK_7,                      6 )
	TAGKEYS(                        XK_8,                      7 )
	TAGKEYS(                        XK_9,                      8 )
	TAGKEYS(			            XK_0,                      9 )
	{ MODKEY,                       XK_q,      quit,           {0} },
	{ MODKEY|ControlMask,		XK_b,	   spawn,	   {.v = browsercmd } },
};

static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

