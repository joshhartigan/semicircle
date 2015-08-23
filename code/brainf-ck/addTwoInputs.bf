,    read character and store in cell 1
>    move pointer to cell 2
,    read character and store in cell 2
[    begin loop {
    <   move to cell 1
    +   increment value
    >   move to cell 2
    -   decrement value
]    exit loop when cell 2 is empty
<    go back to cell 1
------------------------------------------------    subtract 48
.    print value of cell 1
