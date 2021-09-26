// Astronavigation
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

(function AstroNavigation() {
    "use strict";

    function starCode(n) {
        var codes = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz';
        return codes.substr(n,1);
    }

    function run() {
        var starCatalog = readStarCatalog();
        // printClosestStars(starCatalog);
        processBatch(starCatalog);
        // printStarChart( starCatalog );
    }

    function readStarCatalog() {
        var starCatalog = [ ];
        var propertyData = [
            { name: 'catalogName', type: 'string' },
            { name: 'classification', type: 'string' },
            { name: 'absoluteMagnitude', type: 'number' },
            { name: 'x', type: 'number' },
            { name: 'y', type: 'number' },
            { name: 'z', type: 'number' }
        ];

        var numberOfStars = parseInt( stdin.readLine() );

        for( var i=0; i<numberOfStars; ++i ) {
            var starInfo = { };
            var fields = stdin.readLine().split(/ +/);
            // var line = '';
            for( var f=0; f<fields.length; ++f ) {
                var value = fields[f].trim();
                if( propertyData[f].type === "number" ) {
                    value = parseFloat(value);
                }
                // line += value + ',';
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

    function calculateDistance(star0,star1) {
        var dx = star0.x - star1.x;
        var dy = star0.y - star1.y;
        var dz = star0.z - star1.z;
        return Math.sqrt( dx*dx + dy*dy + dz*dz );
    }

    function printClosestStars(starCatalog) {
        for( var s0=0; s0<starCatalog.length; ++s0 ) {
            var minDistance = 9e99;
            var nearestNeighbor = 'UNKNOWN';
            for( var s1=0; s1<starCatalog.length; ++s1 ) {
                if( s0 === s1 ) {
                    continue;
                }
                var distance = calculateDistance(starCatalog[s0],starCatalog[s1]);
                if( minDistance > distance ) {
                    minDistance = distance;
                    nearestNeighbor = starCatalog[s1].catalogName;
                }
            }
            if( minDistance > 16 )
            stdout.writeLine( starCatalog[s0].catalogName + ': ' + nearestNeighbor + ', ' + minDistance + ' LY' );
        }
    }

    function processBatch(starCatalog) {
        var numberOfJourneys = parseInt( stdin.readLine() );
        for( var i=0; i<numberOfJourneys; ++i ) {
            var journey = readJourney();
            // var route = navigate( journey, starCatalog );
            var route = aStar( journey, starCatalog );
            printRoute( journey, route, starCatalog );
        }
    }

    function readJourney() {
        var items = stdin.readLine().split(/ +/);
        var DEBUG_TEXT = 'JOURNEY ITEMS: ';
        for( var i=0; i<items.length; ++i ) {
            DEBUG_TEXT += ' '+i+':'+items[i];
        }
        // stdout.writeLine(DEBUG_TEXT);
        return {
            origination: items[0].trim(),
            destination: items[1].trim(),
            maximumJump: parseFloat(items[2])
        };
    }

    function printRoute( journey, route, starCatalog ) {
        var source = starCatalog[ journey.originationIndex ];
        var target = starCatalog[ journey.destinationIndex ];
        stdout.writeLine('JOURNEY from '+source.catalogName+' to '+target.catalogName + ', max jump: ' + journey.maximumJump + ' LY');
        stdout.writeLine('STRAIGHT LINE DISTANCE: '+calculateDistance( source, target ).toFixed(2)+' LY');
        if( route.length < 2 ) {
            stdout.writeLine('No route from '+source.catalogName+' to '+target.catalogName);
        }
        else {
            stdout.writeLine('number of jumps: '+(route.length-1));
            var totalDistance = 0;
            for( var i=1; i<route.length; ++i ) {
                var source = starCatalog[ route[i-1] ];
                var target = starCatalog[ route[i] ];
                var distance = calculateDistance( source, target );
                stdout.writeLine( source.catalogName+routeCode(i-1)+' to '+target.catalogName+routeCode(i)+'; '+distance.toFixed(2)+' LY' );
                totalDistance += distance;
            }
            stdout.writeLine('Total Distance: '+totalDistance.toFixed(2)+' LY');
        }
        stdout.writeLine('');

        function routeCode(n) {
            // this was helpful for debugging
            // return '('+starCode(route[n])+')';
            return '';
        }
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

    function aStar( journey, starCatalog ) {

        return findPath();

        function findPath() {
            for( var s0=0; s0<starCatalog.length; ++s0 ) {
                if( starCatalog[s0].catalogName === journey.origination )
                    journey.originationIndex = s0;
                if( starCatalog[s0].catalogName === journey.destination )
                    journey.destinationIndex = s0;
            }
            var start = journey.originationIndex;
            var goal = journey.destinationIndex;

            var closedSet = [ ];
            var openSet = [ start ];
            var cameFrom = { };
            var gScoreMap = { };
            gScoreMap[start] = 0;
            var fScoreMap = { };
            fScoreMap[start] = heuristicCostEstimate( start, goal );

            while( openSet.length ) {
                var current = getIndexLowestFScoreNodeInOpenSet( openSet, fScoreMap );
                if( current === goal ) {
                    return reconstructPath( cameFrom, goal );
                }
                // stdout.writeLine('remove '+current+' from openSet');
                removeItemFromArray( openSet, current );
                closedSet.push( current );
                var neighbors = getNeighbors( current );
                for( var i=0; i<neighbors.length; ++i ) {
                    var neighbor = neighbors[i];
                    if( findInArray( closedSet, neighbor ) >= 0 ) {
                        // ignore neighbors that have already been discovered
                        continue;
                    }
                    // stdout.writeLine('cost from '+current+' to '+neighbor);
                    // dump('  starCatalog[current]',starCatalog[current]);
                    // dump('  starCatalog[neighbor]',starCatalog[neighbor]);
                    var tentativeG = getScore( gScoreMap, current ) +
                            calculateDistance( starCatalog[current], starCatalog[neighbor] );
                    if( findInArray( openSet, neighbor ) === -1 ) {
                        // stdout.writeLine('add '+neighbor+' to openSet');
                        // this is a new node
                        openSet.push( neighbor );
                    }
                    else if( tentativeG >= getScore( gScoreMap, neighbor ) ) {
                        // this is not a better path
                        continue;
                    }
                    // this is the best path so far
                    cameFrom[neighbor] = current;
                    gScoreMap[neighbor] = tentativeG;
                    fScoreMap[neighbor] = tentativeG + calculateDistance( starCatalog[neighbor], starCatalog[goal] );
                }
            }
            return [ ];
        }

        function getScore(map,index) {
            return map[index] || Infinity;
        }

        function heuristicCostEstimate(start,goal) {
            // stdout.writeLine('heuristicCostEstimate from '+start+' to '+goal);
            var distance = calculateDistance(starCatalog[start],starCatalog[goal]);
            return distance;
        }

        function findInArray( list, value ) {
            for( var i=0; i<list.length; ++i ) {
                if( list[i] === value ) {
                    return i;
                }
            }
            return -1;
        }

        function removeItemFromArray( list, value ) {
            var index = findInArray( list, value );
            if( index >= 0 ) {
                list.splice(index,1);
            }
        }

        function getIndexLowestFScoreNodeInOpenSet( openSet, fScoreMap ) {
            var lowestScoreIndex = openSet[0];
            var lowestScore = getScore( fScoreMap, 0 );
            for( var i=1; i<openSet.length; ++i ) {
                var score = getScore( fScoreMap, openSet[i] );
                if( score < lowestScore ) {
                    lowestScore = score;
                    lowestScoreIndex = openSet[i];
                }
            }
            return lowestScoreIndex;
        }

        function getNeighbors( current ) {
            var neighbors = [ ];
            for( var i=0; i<starCatalog.length; ++i ) {
                if( i !== current && calculateDistance( starCatalog[i], starCatalog[current] ) <= journey.maximumJump ) {
                    neighbors.push( i );
                }
            }
            return neighbors;
        }

        function reconstructPath( cameFrom, index ) {
            var path = [ index ];
            while( typeof(cameFrom[index]) === 'number' ) {
                index = cameFrom[ index ];
                path.unshift( index );
            }
            return path;
        }

    }

    run();

})();


function dump(label,object) {
    for( var propertyName in object ) {
        stdout.writeLine(label+'.'+propertyName+'='+object[propertyName]);
    }
}
