type test = {
  userId: int,
  id: int,
  title: string,
  body: string,
};

module Decode = {
  let test = json =>
    Json.Decode.{
      userId: field("userId", int, json),
      id: field("id", int, json),
      title: field("title", string, json),
      body: field("body", string, json),
    };
};

let handler = (event, _, callback) => {
  /* let event = event |. (AwsLambda.Sns.records) |. AwsLambda.Sns._EventSource; */
  let event2 = AwsLambda.Sns.records(event)[0] |. AwsLambda.Sns.eventSource;
  Js.log("Hello, BuckleScript and Reason!" ++ event2);
  Http.Client.get("https://play.google.com/log?format=json", response => {
    callback(Js.Nullable.return(Js.Exn.raiseError("WAZAAA")));
    callback(Js.Nullable.null);
  });
};

Http.Client.get("http://jsonplaceholder.typicode.com/posts/1", response => {
  let results = [||];
  response
  |. Http.IncomingMessage.on(
       `data(
         data => {
           let results = Array.append(results, [|data|]);
           response
           |. Http.IncomingMessage.on(
                `_end(
                  () =>
                    Js.log(
                      results |> Buffer.concatArray |> Buffer.toString,
                      /* let decodedTest =
                           data |> Buffer.toString |> Json.parseOrRaise |> Decode.test;
                         Js.log(decodedTest); */
                    ),
                ),
              );
         },
       ),
     );
});