// Variable Shift Encoding
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

   function run() {
      var numberOfLines = parseInt( stdin.readLine() );
      var process = decode;
      if( numberOfLines < 0 ) {
         numberOfLines = - numberOfLines;
         process = encode;
      }
      for( var i=0; i<numberOfLines; ++i ) {
          var groups = readInputLine();
          process( groups );
      }
   };

   function readInputLine() {
      return stdin.readLine()
                  .trim()
                  .split(".");
   };
   
   function encode( groups ) {
      if(DEBUG) stdout.writeLine( "THERE ARE " + groups.length + " GROUPS" );
      for( var i=0; i<groups.length; ++i ) {
         var text = groups[i];
         if( !text.length )
            continue;
         if(DEBUG) stdout.writeLine( "TEXT HAS " + text.length + " CHARACTERS" );
         var codeList = [ ];
         for( var t=0; t<text.length; ++t ) {
            codeList.push( null );
         }
         var offset = 0;
         var delta = 0;
         for( var t=0; t<text.length; ++t ) {
            var c = text[t]; // .charCodeAt(t);
            if(DEBUG) stdout.writeLine( "Next character is '" + c + "'" );
            offset = advanceOffset( codeList, offset, delta, codeList.length );
            codeList[offset] = c;
            delta = 6;
            if(DEBUG) stdout.writeLine( joinCodeList( codeList ) );
            if( c >= '0' && c <= '9' ) {
               delta = ( c.charCodeAt(0) - '0'.charCodeAt(0) ) % 5 + 1;
            }
            else if( c >= 'A' && c <= 'Z' ) {
               delta = ( c.charCodeAt(0) - 'A'.charCodeAt(0) ) % 5 + 1;
            }
            if(DEBUG) stdout.writeLine( "DELTA IS " + delta );
         }
         stdout.write( joinCodeList( codeList ) + "." );
      }
      stdout.writeLine( "" );
   };

   function joinCodeList( codeList ) {
      var s = "";
      for( var i=0; i<codeList.length; ++i ) {
         s += codeList[i] ? codeList[i] : "#";
      }
      return s;
   };

   function advanceOffset( codeList, offset, delta, maxSize ) {
      var nextOffset = offset;
      for( var d=0; d<delta; ++d ) {
         nextOffset = incrementOffset( codeList, nextOffset, maxSize );
      }
      if(DEBUG) stdout.writeLine( "offset(" + offset + ") + delta(" + delta + ") = " + nextOffset );
      return nextOffset;
   };

   function incrementOffset( codeList, offset, maxSize ) {
      var SANITY = maxSize;
      if(DEBUG) stdout.writeLine( "incrementOffset(" + offset + ")" );
      offset = (offset+1) % maxSize;
      if(DEBUG) stdout.writeLine( "    offset=" + offset );
      while( codeList[offset] !== null ) {
         offset = (offset+1) % maxSize;
         if( SANITY-- < 0 ) { console.log("INSANE!!!!"); break; }
      }
      if(DEBUG) stdout.writeLine( "    return(" + offset + ")" );
      return offset;
   };

   function decode( groups ) {
      for( var i=0; i<groups.length; ++i ) {
         var text = groups[i];
         if( !text.length )
            continue;

         var charList = [ ];
         var codeList = [ ];
         for( var t=0; t<text.length; ++t ) {
            charList.push( null );
            codeList.push( null );
         }

         var offset = 0;
         var delta = 0;
         for( var t=0; t<text.length; ++t ) {
            // var c = text[t]; // .charCodeAt(t);

            offset = advanceOffset( codeList, offset, delta, codeList.length );
            var c = text[ offset ];
            codeList[offset] = c;
            if(DEBUG) stdout.writeLine( "text: '" + text + "' -- Character at offset " + offset + " is '" + c + "'" );
            charList[t] = c;
            delta = 6;

            if( c >= '0' && c <= '9' ) {
               delta = ( c.charCodeAt(0) - '0'.charCodeAt(0) ) % 5 + 1;
            }
            else if( c >= 'A' && c <= 'Z' ) {
               delta = ( c.charCodeAt(0) - 'A'.charCodeAt(0) ) % 5 + 1;
            }
            if(DEBUG) stdout.writeLine( "DELTA IS " + delta );

         }
         stdout.write( joinCodeList( charList ) + "." );
      }
      stdout.writeLine( "" );
   };

   run();

}) ();
