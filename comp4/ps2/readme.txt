/**********************************************************************
 *  ps2-readme template                                                   
 *  Recursive Graphics (Pythagoras tree)                       
 **********************************************************************/

Your name: Alex Pereira

Hours to complete assignment: ~4 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
This assignment impliments a "recursive tree" graphic known as Pythagoras tree. 
It takes arguments from the user describing the size of the original square,
and how many levels of recursion that the user desires.

 /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
-Knowing tree traversale helped a lot with this assignment. The tree itself is 
recursive in nature, similar to how a binary tree is recursive.
-SFML has a lot of inherited classes. Reading the docs and knowing which methods 
were available from parent classes helped a lot.


/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
To build the tree, I implimented a working of pre-order traversal. That is,
a shape would build itself, then call the constructors for it's left and right
children (self, left, right) until the base case was reached.

// constructor called
    // Base case
    if (depth <= 0) {
        return;
    }

  this->self = new sf::RectangleShape(sf::Vector2f(size, size));
  /**** misc. logic to place square on screen ****/
  if (depth >= 1) {
        this->left = new Ptree(size * SCALE, angle - 45, 'L', this->getGlobalPoint(0), depth - 1);
        this->right = new Ptree(size * SCALE, angle + 45, 'R', this->getGlobalPoint(1), depth - 1);
    }

 /**********************************************************************
 *  Briefly explain what you learned in the assignment.
 **********************************************************************/
I learned that graphics involve a lot more logic and math than I had 
previously thought. 


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
Lots of reading SFML documentation and posts on stackoverflow


/**********************************************************************
 *  Describe any serious problems you encountered.  
 *  If you didn't complete any part of any assignment, 
 *  the things that you didn't do, or didn't get working.                  
 **********************************************************************/



/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 I found this assignment to be really difficult logic wise but a fun challenge.
 Trying to think in terms of different angles was tough once we got past the first level of recursion!
