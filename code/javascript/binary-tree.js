// binary tree implementation in JavaScript

// a node:
var lonelyNode = {
  data: 58,
  leftChild: null,
  rightChild: null
};


// a tree:
var smallTree = {
  data: 44, // root node

  leftChild: { // same as `lonelyNode`
    data: 58,
    leftChild: null,
    rightChild: null
  };

  rightChild: {
    data: 92,
    leftchild: null,
    rightChild: null
  };
};


// recursive 'tree contains' function
var contains = function(tree, value) {

  if (tree === null) {
    return false;
  }

  if ( value === tree.data ) {
    return true;
  }

  if ( value < tree.data ) {
    return contains( tree.leftChild, value );
  } else {
    return contains( tree.rightChild, value );
  }

};


// recursive 'count nodes' function
var count = function(tree) {

  if (tree === null) {
    return 0;
  }

  if ( tree.leftChild === null && tree.rightChild === null ) {
    return 1; // 1 for the root node
  } else {
    return 1 + count( tree.leftChild ) + count( tree.rightChild );
  }

};

