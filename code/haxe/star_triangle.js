// Compiled from Haxe 3.1.3
(function () { "use strict";
var Test = function() { };
Test.main = function() {
	var _g = 1;
	while(_g < 6) {
		var i = _g++;
		var _g1 = 0;
		while(_g1 < i) {
			var j = _g1++;
			console.log("*");
		}
		console.log("");
	}
};
Test.main();
})();
