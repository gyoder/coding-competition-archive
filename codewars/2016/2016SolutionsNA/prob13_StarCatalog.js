// Star Catalog
// Code Wars program written in JavaScript for the RingoJS environment
//
// The MIT License (MIT)
//
// Copyright (c) 2016 Lee Jenkins
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

(function StarCatalog() {
    "use strict";

    function starCode(n) {
        var codes = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz';
        return codes.substr(n,1);
    }

    function run() {
        var starCatalog = readStarCatalog();
        convertToCartesian(starCatalog);
        // printStarChart( starCatalog );
    }

    function readStarCatalog() {
        var starCatalog = [ ];
        var propertyData = [
            { name: 'catalogName', type: 'string' },
            { name: 'raHours', type: 'number' },
            { name: 'raMinutes', type: 'number' },
            { name: 'decDegrees', type: 'number' },
            { name: 'decMinutes', type: 'number' },
            { name: 'classification', type: 'string' },
            { name: 'absoluteMagnitude', type: 'string' },
            { name: 'distanceLY', type: 'number' },
            { name: 'properName', type: 'string' },
            { name: 'notes', type: 'string' }
        ];

        var numberOfStars = parseInt( stdin.readLine() );

        for( var i=0; i<numberOfStars; ++i ) {
            var starInfo = { };
            var fields = stdin.readLine().split(/ +/);
            var line = '';
            for( var f=0; f<fields.length; ++f ) {
                var value = fields[f].trim();
                if( propertyData[f].type === "number" ) {
                    value = parseFloat(value);
                }
                line += value + ',';
                starInfo[ propertyData[f].name ] = value;
            }
            starCatalog.push( starInfo );
            // stdout.writeLine(line);
        }
        return starCatalog;
    }

    function cosd(angleDegrees) {
        return Math.cos( angleDegrees * Math.PI / 180 );
    }

    function sind(angleDegrees) {
        return Math.sin( angleDegrees * Math.PI / 180 );
    }

    function convertToCartesian(starCatalog) {
        // stdout.writeLine('____________________/ convertToCartesian \\__________');
        for( var s0=0; s0<starCatalog.length; ++s0 ) {
            var star = starCatalog[s0];
            var decSign = star.decDegrees / Math.abs(star.decDegrees) || 1;
            var theta = 90 - decSign * ( Math.abs(star.decDegrees) + star.decMinutes/60 );
            var phi = 15 * ( star.raHours + star.raMinutes/60 );
            star.x = star.distanceLY * sind(theta) * cosd(phi);
            star.y = star.distanceLY * sind(theta) * sind(phi);
            star.z = star.distanceLY * cosd(theta);
            // stdout.writeLine( starCatalog[s0].catalogName + // ': t=' + theta + ' f=' + phi + ', ' +
            //        ' x='+star.x.toFixed(2)+
            //        ', y='+star.y.toFixed(2)+
            //        ', z='+star.z.toFixed(2) );
            stdout.writeLine(
                fw( starCatalog[s0].catalogName, 24 ) + ' '+
                fw( starCatalog[s0].classification, 20 ) + ' '+
                fw( starCatalog[s0].absoluteMagnitude, -5 ) + ' '+
                fw( star.x.toFixed(3), -8 )+ ' '+
                fw( star.y.toFixed(3), -8 )+ ' '+
                fw( star.z.toFixed(3), -8 )
            );
        }
        // stdout.writeLine('####################\\ convertToCartesian /########');
    }

    function fw( value, width ) {
        value = '' + value;
        if( width < 0 ) {
            width = -width;
            while( value.length < width ) {
                value = ' ' + value;
            }
        }
        else {
             while( value.length < width ) {
                value += ' ';
            }
        }
        return value;
    }

    function calculateDistance(star0,star1) {
        var dx = star0.x - star1.x;
        var dy = star0.y - star1.y;
        var dz = star0.z - star1.z;
        return Math.sqrt( dx*dx + dy*dy + dz*dz );
    }

    // print a star chart. not part of the problem, but cool.
    function printStarChart( starCatalog ) {
        var R = 45;
        var DIVIDER = '  |  ';

        function makeHeader( s ) {
            s = '==========[ ' + s + ' ]';
            while( s.length < 1+R*2 ) {
                s += '=';
            }
            return s;
        }
        function makeChart( xAxis, yAxis ) {
            var x, y, chart = [ ];
            for( var y=-R; y<=R; ++y ) {
                var row = [ ];
                for( var x=-R; x<=R; ++x ) {
                    row.push('.');
                }
                chart.push(row);
            }
            for( var i=0; i<starCatalog.length; ++i ) {
                x = Math.floor( starCatalog[i][xAxis] + 0.5 );
                y = Math.floor( starCatalog[i][yAxis] + 0.5 );
                chart[x+R][y+R] = starCode(i);
            }
            return chart
        }
        function printChart(chart1,chart2){
            for( var y=R; y>=-R; --y ) {
                var line1 = '';
                var line2 = '';
                for( var x=-R; x<=R; ++x ) {
                    line1 += chart1[x+R][y+R];
                    line2 += chart2[x+R][y+R];
                }
                stdout.writeLine(line1+DIVIDER+line2);
            }
        }
        var xyChart = makeChart( 'x', 'y' );
        var xzChart = makeChart( 'z', 'y' );

        stdout.writeLine(makeHeader('x,y')+DIVIDER+makeHeader('z,y'));
        printChart(xyChart,xzChart)

    }


    run();

})();
