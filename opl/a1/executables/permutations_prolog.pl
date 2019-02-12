% permut_Prolog(L, P)
% L is a permutation of P

permutations([], []). % Base case, when the lists are empty
% NL is the input list (k), [H | T] is the Head | Tail form of the output list (L)
permutations(NL, [H | T]) :-
	% select seperates the head from the tail, and stores the tail into NL1
    % "after backtracking, it retuns a different element each time.." (see pdf quote in readme) makes it work recursively
    select(H, NL, NL1),
    % recursively call permutations using the seperated tail and the tail of the original list!
    permutations(NL1, T).
