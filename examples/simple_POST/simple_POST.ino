/* RestClient simple GET request
 *
 * credit: Chris Continanza (csquared)
 */

#include "rest_client.h"

RestClient client = RestClient("your-rest-server.com");

//Setup
void setup() {
  Serial.println("Starting...");
}

String response;
void loop(){
  response = "";
  int statusCode = client.post("/data", "POSTDATA", &response);
  Serial.print("Status code from server: ");
  Serial.println(statusCode);
  Serial.print("Response body from server: ");
  Serial.println(response);
  delay(1000);
}
