if has("gui_running")
  highlight Normal guibg=#1b1b1b guifg=#feeedc gui=bold,italic
  highlight Function guifg=#00d1e8 gui=bold,italic
  highlight Identifier guifg=#00d1e8
  highlight PreProc guifg=#fee786
  highlight Operator guifg=#e75d9a gui=bold
  highlight Special guifg=#9fe14d
  highlight Comment guifg=#afe170 gui=italic
  highlight Conditional guifg=#e75d9a gui=bold
  highlight Repeat guifg=#e75d9a gui=bold
  highlight Number guifg=#d28445
  highlight String guifg=#9fe14d
  highlight Constant guifg=#fed631 gui=bold
  highlight Type guifg=#fed631
else
  echo "you must use GUI vim for the mann color scheme"
endif
