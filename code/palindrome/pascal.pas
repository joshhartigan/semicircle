program pascal(output);

function palindrome(s: string): boolean;
var
    result: boolean;
    middleChar: integer;
    lastChar: integer;
    i: integer;
begin
    middleChar := length(s) / 2;
    lastChar := length(s) - 1;

    for i := 1 to middleChar
        if s[i] <> s[lastChar - i] then
            return := false;
    return := true;
end;
