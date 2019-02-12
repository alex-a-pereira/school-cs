(*http://rigaux.org/language-study/syntax-across-languages-per-language/OCaml.html*)
let rec permutations l =
   (* n is len of list l *)
   let n = List.length l in
   (* if len is 1, l is the only permutation so return list *)
   if n = 1 then [l] else
   
   (* define recursive function sub *)
   let rec sub e = function
      (*https://caml.inria.fr/pub/docs/oreilly-book/html/book-ora016.html*)
      (* if in form empty return fail *)
      (* if in form head :: tail, 
      *     if head element is equal to the parameter e value (base case) return the tail end of the list
      *         else set the head the the value return of a recursive call to sub
      *)
      | [] -> failwith "sub"
      | h :: t -> if h = e then t else h :: sub e t in
   
   (* define recursive function aux *)
   let rec aux k =
      (* set e to the value at idx k of list l *)
      let e = List.nth l k in
      (* call sub with argument value e and list l, then call permutations with the result as an arg *)
      let subperms = permutations (sub e l) in
      (* call lambda func on each idx, on list subperms and set t to that list *)
      let t = List.map (fun a -> e::a) subperms in
      (* if count k is less than the max idx of list l, call aux recursively otherwise return list t *)
      if k < n-1 then List.rev_append t (aux (k+1)) else t in
   
   aux 0;; (* call aux with value 0 *)
 
(* define print function for list *)
let print l = List.iter (Printf.printf " %d") l; print_newline() in
(* print list returned from permutations() func *)

(*https://ocaml.org/learn/tutorials/if_statements_loops_and_recursion.html*)
(* double semi colon to end fn def has changed so I had to experiment *)
let rec range a b = 
   if a > b then []
   else a :: range (a+1) b in

(* generate a list of vals from 1 to n *)

let cli_args = Sys.argv in
let string_num = cli_args.(1) in
let num = int_of_string string_num in

let p = range 1 num in
(*let n = 4 in*)
(*let p = List.init n (function i -> i + 1) in*)
List.iter print (permutations p)