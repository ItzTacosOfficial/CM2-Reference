# CM2 Networking

Crazy Machines 2 online functionality works through HTTP POST requests.

Unfortunately all server domains have never been backed up on the Wayback Machine, thus there is no way to reverse engineer the requests the other way around.

Since HTTP is stateless, the original server was written in php to handle session IDs and the client sends heartbeat requests;
thought I unfortunately failed to understand the conditions under which the client sends such requests.


## Command Requests

Command requests are POST requests to `/server/command.php`.

The content type is always `application/x-www-form-urlencoded`.

Every command request has the argument `CMD`, a string identifying the command being issued;
all other arguments are named in the form of `Px` where `x` is an integer starting from 1.

Additionally, all commands marked with **Session** have a `PHPSESSID` argument being the 32-characters php session ID.

All arguments are internally loaded as field-value pairs of type `const wchar_t*`.
In case the value string was to be empty, `###` is used instead (this may be the case for the serial number arguments).


- ### `REGISTER` Online profile register

Registers an online profile with the given parameters.

#### Request

| Argument | Description           | Example                            |
|----------|-----------------------|------------------------------------|
| P1       | Profile name          | `Einstein`                         |
| P2       | Password MD5          | `a8f5f167f44f4964e6c998dee827110c` |
| P3       | Unknown constant      | `17105281`                         |
| P4       | Unknown constant      | `2`                                |
| P5       | Profile icon fst file | `icons.fst`                        |
| P6       | Profile icon name     | `Wrench`                           |
| P7       | Serial number         | `###`                              |

#### Response

Response type is `text/plain`.

| State   | Response | Details |
|---------|----------|---------|
| Success | `OK\n`   |         |
| Failure | `ERR\n`  |         |


- ### `LOGIN` Profile login

Logs into a profile starting a new session.

#### Request

| Argument | Description      | Example                            |
|----------|------------------|------------------------------------|
| P1       | Profile name     | `Einstein`                         |
| P2       | Password MD5     | `a8f5f167f44f4964e6c998dee827110c` |
| P3       | Unknown constant | `17105281`                         |
| P4       | Unknown constant | `2`                                |
| P5       | Serial number    | `###`                              |

#### Response

Response type is `text/plain`.

| State   | Response                               | Details                                             |
|---------|----------------------------------------|-----------------------------------------------------|
| Success | <pre>OK\n<br/>{PHP Session ID}\n</pre> | The game only handles 32-characters long session id |
| Failure | `ERR\n`                                |                                                     |


- ### `LOGOUT` Profile logout (Session)

Logs out the given session.

#### Request

| Argument  | Description                    | Example                           |
|-----------|--------------------------------|-----------------------------------|

#### Response

Response type is `text/plain`.

| State   | Response | Details |
|---------|----------|---------|
| Success | `OK\n`   |         |
| Failure | Anything |         |


- ### `HEARTBEAT` (Session)

#### Request

| Argument  | Description                    | Example                           |
|-----------|--------------------------------|-----------------------------------|

#### Response

Empty


- ### `LABUPLOAD` (Lab level upload)

Unknown


- ### `SOLUPLOAD` (Lab solution upload)

Unknown


- ### `LABDOWNLOAD` (Lab level download)

Unknown


- ### `SOLDOWNLOAD` (Lab solution download)

Unknown


- ### `SKUDOWNLOAD` (Sku download)

Unknown


- ### `GETLABLIST` (Get laboratory list)

Unknown


- ### `GETSOLLIST` (Get solution list)

Unknown


- ### `RATE` (Rate laboratory)

Unknown


- ### `SCORE` (Set completion score)

Unknown


- ### `GETSKULIST` (Get Sku list)

Unknown


- ### `GETSKUINFO` (Get Sku info)

Unknown


- ### `GETMSGFEED` (Get message feed)

#### Request

| Argument | Description      | Example |
|----------|------------------|---------|
| P1       | Language ID      | `0x09`  |
| P2       | Unknown constant | `0`     |
| P3       | Unknown constant | `3`     |


- ### `UPDUSERPROFILE` (Upload user profile)

Unknown


### `GETUSERPROFILE` (Get user profile)

Unknown


## Upload Requests

Upload requests are POST requests to `/server/upload.php`.

The content type is always `application/octet-stream`.

**TODO!**
