-- For help with dumb compilation problems
--https://aada.m2osw.com/gnat-errors/end-file-expected-file-can-have-only-one-compilation-unit

-- I learned a lot about ada and it's system of packaging from this website 
-- https://perso.telecom-paristech.fr/pautet/Ada95/chap15.htm

-- Syntax stuff
-- http://rigaux.org/language-study/syntax-across-languages-per-language/Ada.html

-- Import modules
with Ada.Text_IO, Ada.Command_Line;

procedure permutations is
    -- rename packages to friendly names :)
    package CML renames Ada.Command_Line;
    package TIO renames Ada.Text_IO;
    
    -- GENERIC PERM PACKAGE
    -- header declares types and fn's, like c and c++
    generic
      N: positive; -- this is used like a value constructor
    package Generic_Perm is
      subtype Element is Positive range 1 .. N; -- elements are ints in range from 1 to N
      type Permutation is array(Element) of Element;
    
      procedure Set_To_First(P: out Permutation; Is_Last: out Boolean);
      procedure Go_To_Next(P: in out Permutation; Is_Last: out Boolean); 
    end Generic_Perm;
    
    -- Implimentation
    package body Generic_Perm is
 
      procedure Set_To_First(P: out Permutation; Is_Last: out Boolean) is
      begin
          -- loop to assign idx's of P to the value of the loop
          -- P'Range defines stopping point because elements are in range 1..N
          for I in P'Range loop
            P (I) := I;
          end loop;
          Is_Last := P'Length = 1; -- sets "done" flag when there's only one permutations
      end Set_To_First;
    
      procedure Go_To_Next(P: in out Permutation; Is_Last: out Boolean) is
        -- define the swap function that we're all familiar with
        procedure Swap (A, B : in out Integer) is
          C : Integer := A;
        begin
          A := B;
          B := C;
        end Swap;

        I, J, K : Element; -- Declare vars
        begin
        -- find longest tail decreasing sequence
        -- after the loop, this sequence is I+1 .. n,
        -- and the ith element will be exchanged later
        -- with some element of the tail
        Is_Last := True; 
        I := N - 1;
        
        -- 
        loop
          if P (I) < P (I+1) 
          then
            Is_Last := False; -- we're done unless element at idx I is >= it's neighbor
            exit; -- break
          end if;

          -- next instruction will raise an exception if I = 1, so
          -- exit now (this is the last permutation)
          exit when I = 1;
          I := I - 1;
        end loop;

        -- if all the elements of the permutation are in
        -- decreasing order, this is the last one
        if Is_Last then
          return;
        end if;

        -- sort the tail, i.e. reverse it, since it is in decreasing order
        J := I + 1;
        K := N;
        while J < K loop
          Swap (P (J), P (K));
          J := J + 1;
          K := K - 1;
        end loop;

        -- find lowest element in the tail greater than the ith element
        J := N;
        while P (J) > P (I) loop
          J := J - 1;
        end loop;
        J := J + 1;

        -- exchange them
        -- this will give the next permutation in lexicographic order,
        -- since every element from ith to the last is minimum
        Swap (P (I), P (J));
      end Go_To_Next;

    end Generic_Perm; -- end impl

begin -- definition of procedure permutations begins here 
   declare
      -- basiocally creating an object
      package Perms is new Generic_Perm(Positive'Value(CML.Argument(1)));
      -- declare vars
      P : Perms.Permutation;
      Done : Boolean := False; -- flag to break loop
      -- define the fn to print our permutations type
      procedure Print(P: Perms.Permutation) is
      begin
         for I in P'Range loop
            TIO.Put (Perms.Element'Image (P (I)));
         end loop;
         TIO.New_Line;
      end Print;         
   begin -- implimentation of permutations procedure
      Perms.Set_To_First(P, Done);
      loop
         Print(P);
         exit when Done;
         Perms.Go_To_Next(P, Done);
      end loop;
   end;
exception -- error handling when arg isn't entered!
   when Constraint_Error 
     => TIO.Put_Line ("*** Error: enter one numerical argument n with n >= 1");
end permutations;

