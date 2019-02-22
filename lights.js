$(document).ready(function() { // do this when the document is loaded
  $("#content_presets").show();
	$("#content_custom").hide();
  $("#content_help").hide();



});


$("#preset_tab_btn").click(function() { // when "presets_tab" is clicked
$("#content_presets").show();
$("#content_custom").hide();
$("#content_help").hide();
});

$("#custom_tab_btn").click(function() { // when "custom_tab" is clicked
$("#content_presets").hide();
$("#content_custom").show();
$("#content_help").hide();
});

$("#help_tab_btn").click(function() { // when "help_tab" is clicked
$("#content_presets").hide();
$("#content_custom").hide();
$("#content_help").show();
});

$(".circle").click(function() {
  var clickBtnValue = $(this).val();
  var ajaxurl = 'ajax.php',
  data = {'action': clickBtnValue};
  $.post(ajaxurl, data, function(response) {
  });

});
