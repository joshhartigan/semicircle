$(function() {

  repositories = [
    "banana",
    "css-quest",
    "entation",
    "intrst",
    "josh",
    "joshhartigan.github.io",
    "js-game",
    "lab",
    "lishp",
    "minim",
    "MUtils",
    "other-snakes",
    "rembrandt.js",
    "semicircle",
    "SimpleCommenter",
    "skwhere",
    "square-games",
    "style",
    "tests",
    "try-assembly",
    "vim-guitar",
    "vimrc"
  ];

  $(".search").on( "keyup", function() {
    for (var r = 0; r < repositories.length; r++) {
      var repo = repositories[r];
      var searchText = $(".search").val();

      if ( searchText.trim() != "" && repo.indexOf(searchText) == 0 ) {
        $(".results").append("<p>" + repo + "</p>");
      } else {
        var oldHtml = $(".results").html();
        var newHtml = oldHtml.replace("<p>" + repo + "</p>", "");
        $(".results").html(newHtml);
      }
    }
  });

});
