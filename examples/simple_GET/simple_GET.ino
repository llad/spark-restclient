/* RestClient simple GET request
 *
 * credit: Chris Continanza (csquared)
 */

#include "rest_client.h"

RestClient client = RestClient("your-rest-server.com");

//Setup
void setup() {
  Serial.begin(9600);
  Serial.println("starting...");

}

String response;
void loop(){
  response = "";
  int statusCode = client.get("/path", &response);
  Serial.print("Status code from server: ");
  Serial.println(statusCode);
  Serial.print("Response body from server: ");
  Serial.println(response);
  delay(1000);
}
