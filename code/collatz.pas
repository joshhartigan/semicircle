(* Unoriginal program, I had no ideas :( *)

program collatz(output);

var
    i: integer; (* used in for loop *)
    c: integer;

function calculateCollatz(n : integer): integer;
(* local variables: *)
var
    result : integer;
begin
    if n = 1 then
        result := 1
    else if n mod 2 = 0 then
        result := n div 2
    else
        result := 3 * n + 1
end;

(* 'main' function: *)
begin
    c := calculateCollatz(55); (* => 166 *)
    writeln(c);

    c := calculateCollatz(40); (* => 20 *)
    writeln(c);

    c := calculateCollatz(25); (* => 76 *)
    writeln(c);
end.
