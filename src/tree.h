//Daren Shamoun
#ifndef TREE_H
#define TREE_H

// 
// Tree manipulation functions
//

#include <iostream>
#include <string>

namespace mesa 
{
  // a recursive binary tree
  template<class T>
    struct tree 
    {
	  T value = T();
      tree<T>* left = nullptr;
      tree<T>* right = nullptr;

		// constructor
		tree() = default;
		
		tree(T& v, tree<T>* left_ptr)
			: value(v), left(left_ptr)
		{}

		tree(T& v, tree<T>* left_ptr, tree<T>* right_ptr)
			: value(v), left(left_ptr), right(right_ptr)
		{}

		// destructor
		~tree() = default;

		// copy constructor
		tree(const tree<T>& t) 
			: value(t.value), left(t.left), right(t.right) 
		{}

		// move constructor
		tree(tree<T>&& t) 
			: value(t.value), left(t.left), right(t.right) 
		{}	

		// copy assignment
		tree<T>& operator=(const tree<T>& other) 
		{
			if (this == &other) 
			{
				// self-assignment, do nothing
				return *this;
			}

			// Deallocate any memory currently being used by this tree
			mesa::delete_tree(this);

			// Copy the value from the other tree node
			value = other.value;

			// Recursively copy the left and right subtrees
			if (other.left != nullptr) 
			{
				left = new tree<T>{ *other.left };
			}
			if (other.right != nullptr) 
			{
				right = new tree<T>{ *other.right };
			}

			return *this;
		}

		// move assignment
		tree<T>& operator=(tree<T>&& other)
		{
			if (this != &other)
			{
				// Deallocate any memory currently being used by this tree
				mesa::delete_tree(this);

				// Move the value and subtrees from the other tree
				value = std::move(other.value);
				left = other.left;
				right = other.right;

				// Null out the other tree's pointers
				other.left = nullptr;
				other.right = nullptr;
			}
			return *this;
		}
	};
} // end namespace mesa
#endif