// Location Awareness
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

(function LocationAwareness() {

   function run() {
      var signals = readSignals();
      var REALLY_BIG_NUMBER = 9E999; // distance is "infinity" for input 0 0 0
      while( signals[0].distance < REALLY_BIG_NUMBER ) {
         solve( signals );
         signals = readSignals();
      }
   };

   function readSignals() {
      var tokens = stdin.readLine().trim().split(/\s/);
      /* we know that s = P / ( d*d ); solve for d and get d = sqrt( P / s ).
         the trouble is we don't know P, but it really doesn't matter because
         P has the same value for all three signals. so we can let P = 1 and
         then look at the ratios of the signals. as long as all our distance
         calculations use the same P=1 value, everything will work out OK. */
      var relativeDistances = [
         1 / Math.sqrt( parseFloat(tokens[0])),
         1 / Math.sqrt( parseFloat(tokens[1])),
         1 / Math.sqrt( parseFloat(tokens[2]))
      ];
      var signals = [{
            distance: relativeDistances[0],
            x: 0,
            y: 100,
            ratios: [ ]
         },{
            distance: relativeDistances[1],
            x: -100,
            y: -100,
            ratios: [ ]
         },{
            distance: relativeDistances[2],
            x:  100,
            y: -100,
            ratios: [ ]
      }];
      if(DEBUG) stdout.writeLine( relativeDistances[0] + " " + relativeDistances[1] + " " + relativeDistances[2] );
      for( var i=0; i<3; ++i ) {
         for( var j=0; j<3; ++j ) {
            signals[i].ratios.push( relativeDistances[i] / relativeDistances[j] );
            if(DEBUG) stdout.write( signals[i].ratios[j] + " " );
         }
         if(DEBUG) stdout.writeLine("");
      }
      return signals;
   };

   function solve( signals ) {
      var minPoint = { x: x, y: y, errorSum: 999 };
      for( var x=-99; x<100; ++x ) {
         for( var y=-99; y<100; ++y ) {
            var errorSum = 0;
            var point = { x: x, y: y };
            var distances = [ ];
            for( var i=0; i<3; ++i ) {
               distances.push( getDistance( point, signals[i] ) );
            }
            for( var i=0; i<3; ++i ) {
               for( var j=0; j<3; ++j ) {
                  var ratio = distances[i] / distances[j];
                  var delta = ratio - signals[i].ratios[j];
                  if(DEBUG) stdout.writeLine("  ratio i/j : "+ratio+", target : "+signals[i].ratios[j] + ", error=" + (delta*delta) );
                  errorSum += delta * delta;
               }
            }
            if(DEBUG) stdout.writeLine("  errorSum = " + errorSum + ", point.errorSum = " + minPoint.errorSum );
            if( errorSum < minPoint.errorSum ) {
               minPoint = { x: x, y: y, errorSum: errorSum };
            }
         }
      }
      stdout.writeLine( minPoint.x + " " + minPoint.y );
   };

   function getDistance( p0, p1 ) {
      var dx = p0.x - p1.x;
      var dy = p0.y - p1.y;
      var distance = Math.sqrt( dx*dx + dy*dy );
      if(DEBUG) stdout.writeLine("distance from "+p0.x+","+p0.y+" to "+p1.x+","+p1.y+" is " + distance);
      return distance;
   };

   run();

}) ();
