// Craft Master
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

(function CraftMaster() {

   var recipes = { };
   var recipes = { };

   function run() {
      readRecipes();
      printItemMaterials();
   };

   function readRecipes() {
      var numberOfRecipes = parseInt( stdin.readLine() );
      for( var i=0; i<numberOfRecipes; ++i ) {
         var tokens = stdin.readLine().trim().split(/\s/);
         var itemName = tokens[0];
         var numberOfIngredients = parseInt( tokens[1] );
         var ingredients = [ ];
         for( var j=0; j<numberOfIngredients; ++j ) {
            var t0 = 2 + 2*j;
            ingredients.push({
               name: tokens[t0+1],
               quantity: tokens[t0]
            })
         }
         recipes[ itemName ] = ingredients;
      }
   };

   function printItemMaterials() {
      var itemName = stdin.readLine().trim();
      while( itemName !== "GO" ) {
         var materialSet = { };
         getMaterialSet( materialSet, itemName, 1 );
         var materialList = sortMaterials( materialSet );
         stdout.writeLine( "["+itemName+"]" );
         for( var i=0; i<materialList.length; ++i ) {
            stdout.writeLine( materialList[i].name + " " + materialList[i].qty );
         }
         itemName = stdin.readLine().trim();
      }
   };

   function getMaterialSet( materialSet, itemName, quantity ) {
      var ingredients = recipes[ itemName ];
      if( !ingredients ) {
         // use a hash to collect the raw material information because a hash makes it
         // easy to write code to create/update the material counts
         materialSet[itemName] = ( materialSet[itemName] || 0 ) + quantity;
         if(DEBUG) stdout.writeLine( "materialSet["+itemName+"]="+materialSet[itemName] );
      }
      else {
         for( var i=0; i<ingredients.length; ++i ) {
            getMaterialSet( materialSet, ingredients[i].name, ingredients[i].quantity * quantity );
         }
      }
   };

   function sortMaterials( materialSet ) {
      var materialList = [ ];
      // convert the material information to an array so we can sort it by name
      for( var itemName in materialSet ) {
         materialList.push({
            name: itemName,
            qty: materialSet[itemName]
         })
      }
      materialList.sort(function(a,b){
         if( a.name < b.name ) return -1;
         if( a.name > b.name ) return 1;
         return 0;
      });
      return materialList;
   };

   run();

}) ();
