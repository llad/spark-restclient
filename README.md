# RestClient for the Spark Core

HTTP Request library for the Spark Core.  A lightly adjusted version of the RestClient for Arduino from Chris Continanza  available here: https://github.com/csquared/arduino-restclient

# Install

Add the files `rest_client.cpp` and `rest_client.h` to your app somehow... I just cut and paste into the Spark.io Web IDE.

# Usage


### RestClient(host/ip, [port])

Constructor to create an RestClient object to make requests against.

Use domain name and default to port 80:
```c++
RestClient client = RestClient("www.some-http-server.com");
```

Use a local IP and an explicit port:
```c++
RestClient client = RestClient("192.168.1.50",5000);
```

## RESTful methods

All methods return an HTTP status code or 0 if there was an error.

### `get(const char* path)`
### `get(const char* path, String* response)`

Start making requests!

```c++
int statusCode = client.get("/"));
```

Pass in a string *by reference* for the response:
```
String response = "";
int statusCode = client.get("/", &response);
```

### post(const char* path, const char* body)
### post(const char* path, String* response)
### post(const char* path, const char* body, String* response)

```
String response = "";
int statusCode = client.post("/", &response);
statusCode = client.post("/", "foo=bar");
response = "";
statusCode = client.post("/", "foo=bar", &response);
```

### put(const char* path, const char* body)
### put(const char* path, String* response)
### put(const char* path, const char* body, String* response)

```
String response = "";
int statusCode = client.put("/", &response);
statusCode = client.put("/", "foo=bar");
response = "";
statusCode = client.put("/", "foo=bar", &response);
```

### del(const char* path)
### del(const char* path, const char* body)
### del(const char* path, String* response)
### del(const char* path, const char* body, String* response)

```
String response = "";
int statusCode = client.del("/", &response);
```

## Full Example

I test every way of calling the library (against a public heroku app)[https://github.com/csquared/arduino-http-test].

You can find the file in File->Examples->RestClient->full_test_suite

## Debug Mode

If you're having trouble, you can always open `RestClient.cpp` and throw at the top:

```c++
#define HTTP_DEBUG
```

Everything happening in the client will get printed to the Serial port.

# Thanks/Credit

So far, I have just made a few minor adjustments to the excellent work of Chris Continanza, available here: https://github.com/csquared/arduino-restclient.  Thanks, Chris!

