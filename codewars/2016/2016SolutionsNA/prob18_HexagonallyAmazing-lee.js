// Hexagonally Amazing
// Code Wars program written in JavaScript for the RingoJS environment
//
// The MIT License (MIT)
//
// Copyright (c) 2015 Lee Jenkins
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

var stdin = require("system").stdin;
var stdout = require("system").stdout;

"use strict";

var DEBUG = false;

(function VariableShiftEncoding() {

   var STEPS = [
      { dr:  0, dc: -4 },
      { dr:  0, dc:  4 },
      { dr:  2, dc:  2 },
      { dr: -2, dc:  2 },
      { dr: -2, dc: -2 },
      { dr:  2, dc: -2 },
   ];

   function run() {
      var size = readInputSize();
      var maze = readMaze( size );
      var solution = solve( maze );
      printOut( solution );
   };

   function readInputSize() {
      var tokens = stdin.readLine()
                        .trim()
                        .split(" ");
      return {
         rows: parseInt(tokens[0]),
         cols: parseInt(tokens[1])
      };
   };

   function readMaze( size ) {
      var maze = [ ];
      var padLength = ( size.cols - 1 ) * 4 + 1;
      for( var r=0; r<2*size.rows-1; ++r ) {
         var line = stdin.readLine();
         var row = line.split('');
         // pull CRs and LFs off the end of the line
         while( row[ row.length-1 ] < ' ' ) {
            row.pop();
         }
         while( row.length < padLength ) {
            row.push(' ');
         }
         maze.push( row );
      }
      return maze;
   };

   function solve( maze ) {
      var start = { row: -1, col: -1 };
      var solution = [ ];
      for( var r=0; r<maze.length; ++r ) {
         var row = [ ];
         for( var c=0; c<maze[r].length; ++c ) {
            if( maze[r][c] === '@' ) {
               start = { row: r, col: c };
            }
            row.push( maze[r][c] );
         }
         solution.push( row );
      }
      stepSolve( maze, solution, start, 'A' );
      return solution;
   };

   function stepSolve( maze, solution, pos, letter ) {
      var nextLetter = String.fromCharCode( letter.charCodeAt(0) + 1 );
      for( var i=0; i<STEPS.length; ++i ) {
         var node = { row: pos.row + STEPS[i].dr,   col: pos.col + STEPS[i].dc   };
         var link = { row: pos.row + STEPS[i].dr/2, col: pos.col + STEPS[i].dc/2 };
         if( isValid(node,maze) && isConnected(link,maze) ) {
            if(DEBUG) stdout.writeLine( "HEXAGON AT NEXT POSITION IS " + solution[node.row][node.col] );
            if( isSolutionChar(node,solution,'?') ) {
               return true;
            }
            else if( isSolutionChar(node,solution,'#') ) {
               solution[node.row][node.col] = letter;
               if(DEBUG) printOut( solution );
               if( stepSolve( maze, solution, node, nextLetter ) ) {
                  return true;
               }
               solution[node.row][node.col] = '#';
            }
         }
      }
      return false;
   };

   function isValid( node, maze ) {
      return ( node.row >= 0 && node.row < maze.length &&
               node.col >= 0 && node.col < maze[node.row].length );
   };

   function isSolutionChar( node, solution, c ) {
      return ( solution[node.row][node.col] === c );
   };

   function isConnected( link, maze ) {
      return maze[link.row][link.col] !== ' ';
   };

   function printOut( solution ) {
      for( var r=0; r<solution.length; ++r ) {
         stdout.writeLine( solution[r].join('') );
      }
   };

   run();

}) ();
