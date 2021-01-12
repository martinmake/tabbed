/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[]        = "xos4 Terminus:pixelsize=10";
static const char* normbgcolor  = "#000000";
static const char* normfgcolor  = "#ffffff";
static const char* selbgcolor   = "#ffff00";
static const char* selfgcolor   = "#000000";
static const char* urgbgcolor   = "#ff0000";
static const char* urgfgcolor   = "#000000";
static const char before[]      = "<";
static const char after[]       = ">";
static const char titletrim[]   = "...";
static const int  tabwidth      = 200;
static const Bool foreground    = True;
static       Bool urgentswitch  = False;

/*
 * Where to place a new tab when it is opened. When npisrelative is True,
 * then the current position is changed + newposition. If npisrelative
 * is False, then newposition is an absolute position.
 */
// always after
static int  newposition   = 1;
static Bool npisrelative  = True;
// always first
// static int  newposition   = 0;
// static Bool npisrelative  = False;

#define SETPROP(p) { \
        .v = (char *[]){ "/bin/sh", "-c", \
                "prop=\"`xwininfo -children -id $1 | grep '^     0x' |" \
                "sed -e's@^ *\\(0x[0-9a-f]*\\) \"\\([^\"]*\\)\".*@\\1 \\2@' |" \
                "xargs -0 printf %b | dmenu -l 10 -w $1`\" &&" \
                "xprop -id $1 -f $0 8s -set $0 \"$prop\"", \
                p, winid, NULL \
        } \
}

#define AltMask Mod1Mask
static Key keys[] = {
	/* modifier             key           functin      argument                       */
	{          ControlMask ,XK_Return    ,focusonce   ,{ 0 }                          },
	{          ControlMask ,XK_Return    ,spawn       ,{ 0 }                          },
	{  AltMask|ControlMask ,XK_Return    ,focusonce   ,{ 0 }                          },
	{  AltMask|ControlMask ,XK_Return    ,spawn       ,{ 0 }                          },

	{          ControlMask ,XK_n         ,rotate      ,{ .i = +1 }                    },
	{          ControlMask ,XK_p         ,rotate      ,{ .i = -1 }                    },
	{  AltMask|ControlMask ,XK_l         ,rotate      ,{ .i = +1 }                    },
	{  AltMask|ControlMask ,XK_h         ,rotate      ,{ .i = -1 }                    },
	{  AltMask|ControlMask ,XK_j         ,movetab     ,{ .i = -1 }                    },
	{  AltMask|ControlMask ,XK_k         ,movetab     ,{ .i = +1 }                    },
	{          ControlMask ,XK_Tab       ,rotate      ,{ .i =  0 }                    },
	{  AltMask|ControlMask ,XK_Tab       ,rotate      ,{ .i =  0 }                    },

	{          ControlMask ,XK_s         ,spawn,       SETPROP("_TABBED_SELECT_TAB")  },

	{          ControlMask ,XK_1         ,move        ,{ .i = 0 }                     },
	{          ControlMask ,XK_2         ,move        ,{ .i = 1 }                     },
	{          ControlMask ,XK_3         ,move        ,{ .i = 2 }                     },
	{          ControlMask ,XK_4         ,move        ,{ .i = 3 }                     },
	{          ControlMask ,XK_5         ,move        ,{ .i = 4 }                     },
	{          ControlMask ,XK_6         ,move        ,{ .i = 5 }                     },
	{          ControlMask ,XK_7         ,move        ,{ .i = 6 }                     },
	{          ControlMask ,XK_8         ,move        ,{ .i = 7 }                     },
	{          ControlMask ,XK_9         ,move        ,{ .i = 8 }                     },
	{          ControlMask ,XK_0         ,move        ,{ .i = 9 }                     },
	{  AltMask|ControlMask ,XK_1         ,move        ,{ .i = 0 }                     },
	{  AltMask|ControlMask ,XK_2         ,move        ,{ .i = 1 }                     },
	{  AltMask|ControlMask ,XK_3         ,move        ,{ .i = 2 }                     },
	{  AltMask|ControlMask ,XK_4         ,move        ,{ .i = 3 }                     },
	{  AltMask|ControlMask ,XK_5         ,move        ,{ .i = 4 }                     },
	{  AltMask|ControlMask ,XK_6         ,move        ,{ .i = 5 }                     },
	{  AltMask|ControlMask ,XK_7         ,move        ,{ .i = 6 }                     },
	{  AltMask|ControlMask ,XK_8         ,move        ,{ .i = 7 }                     },
	{  AltMask|ControlMask ,XK_9         ,move        ,{ .i = 8 }                     },
	{  AltMask|ControlMask ,XK_0         ,move        ,{ .i = 9 }                     },

	{          ControlMask ,XK_q         ,killclient  ,{ 0 }                          },

	{  AltMask|ControlMask ,XK_u         ,focusurgent ,{ 0 }                          },
	{          ControlMask ,XK_u         ,toggle      ,{ .v = (void*) &urgentswitch } },

	{  0                   ,XK_F11       ,fullscreen  ,{ 0 }                          },

	{          ControlMask ,XK_Alt_L     ,showbar     ,{ .i = 1 }                     },
	{  AltMask             ,XK_Control_L ,showbar     ,{ .i = 1 }                     }, }; static Key keyreleases[] = {
	{  AltMask|ControlMask ,XK_Alt_L     ,showbar     ,{ .i = 0 }                     },
	{  AltMask|ControlMask ,XK_Control_L ,showbar     ,{ .i = 0 }                     },
};
