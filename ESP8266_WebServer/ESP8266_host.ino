void host() {
  server.send(200, "text/plain", "Home");
  Serial.println(WiFi.localIP());
}
void host_n() {
  server.send(200, "text/plain", "");
  Serial.println(WiFi.localIP());
}
void host_a() {
  server.send(200, "text/html", "\
      <html>\
        <head>\
          <meta charset='utf-8'/>\
          <meta http-equiv='refresh' content='1'/>\
          <meta name='viewport' content='width=device-width;initial-scale=1.0;maximum-scale=1.0;user-scalable=0;'/>\
          <title>host_a</title>\
          <style>body { font-family: '微軟正黑體', '黑體-繁', Sans-Serif;}</style>\
        </head>\
        <body>\
          <h1>NodeMcu</h1>\
          <p>Time=" + x + "</p>\
          <a href='http://google.com'>Google</a>\
        </body>\
      </html>");
  Serial.print(WiFi.localIP());
  Serial.println("/a");
}
void host_b() {
  server.send(200, "text/html", "<html>\
  <head>\
    <meta charset='utf-8'>\
    <meta name='viewport' content='width=device-width, initial-scale=1'>\
    <title>host_b</title>\
    <link href='https://code.jquery.com/ui/1.11.4/themes/smoothness/jquery-ui.css' rel='stylesheet' type='text/css'>\
    <style type='text/css'>\
    body {\
        font-family: '微軟正黑體', '黑體-繁', sans-serif;\
    }\
    </style>\
  </head>\
  <body>\
    <h1>host_b</h1>\
    <br>\
    <div id='LED_SW1'>\
    <button type='button' class='but' value='HIGH' name='SW1'>測試</button>\
    </div>\
    <script src='https://code.jquery.com/jquery-1.12.1.min.js'></script>\
    <script src='https://code.jquery.com/ui/1.11.4/jquery-ui.min.js'></script>\
    <script>\
    $(function() {\
    $( '#LED_SW1' ).buttonset();\
    $('.but').click(function(evt) {\
        var state = $(this).val();\
        $.post('/sw', {led:state});\
    });\
 });\
  </script>\
  </body>\
  </html>");
}
void host_c() {
  String state = server.arg("led");
  if (state == "HIGH") Serial.write("a");
}
void host_NotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++)
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  server.send(404, "text/plain", message);
}
