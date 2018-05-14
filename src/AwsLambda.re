type any;
external any : 'a => any = "%identity";

type error = Js.Nullable.t(Js.Exn.t);

type callback = error => unit;

type resultCallback('result) = (error, 'result) => unit;

type handler('event) = ('event, unit, callback) => unit;

type resultHandler('event, 'result) =
  ('event, unit, resultCallback('result)) => unit;

[@bs.deriving abstract]
type cognitoIdentity = {
  cognitoIdentityId: string,
  cognitoIdentityPoolId: string,
};

[@bs.deriving abstract]
type clientContextClient = {
  installationId: string,
  appTitle: string,
  appVersionName: string,
  appVersionCode: string,
  appPackageName: string,
};

[@bs.deriving abstract]
type clientContextEnv = {
  platformVersion: string,
  platform: string,
  make: string,
  model: string,
  locale: string,
};

[@bs.deriving abstract]
type clientContext = {
  [@bs.as "Custom"]
  custom: Js.Nullable.t(any),
  client: clientContextClient,
  env: clientContextEnv,
};

type getRemainingTimeInMillis = unit => float;

[@bs.deriving abstract]
type context = {
  callbackWaitsForEmptyEventLoop: bool,
  functionName: string,
  functionVersin: string,
  invokedFunctionArn: string,
  memoryLimitInMB: int,
  awsRequestId: string,
  logGroupName: string,
  logStreamName: string,
  identity: Js.Nullable.t(cognitoIdentity),
  clientContext: Js.Nullable.t(clientContext),
  getRemainingTimeInMillis: getRemainingTimeInMillis,
};

module Sns = {
  [@bs.deriving abstract]
  type messageAttribute = {
    [@bs.as "Type"]
    type_: string,
    [@bs.as "Value"]
    value: string,
  };
  [@bs.deriving abstract]
  type messageAttributes = Js.Dict.t(messageAttribute);
  [@bs.deriving abstract]
  type message = {
    [@bs.as "SignatureVersion"]
    signatureVersion: string,
    [@bs.as "Timestamp"]
    timestamp: string,
    [@bs.as "Signature"]
    signature: string,
    [@bs.as "SigningCertUrl"]
    signingCertUrl: string,
    [@bs.as "MessageId"]
    messageId: string,
    [@bs.as "Message"]
    message: string,
    [@bs.as "MessageAttributes"]
    messageAttributes,
    [@bs.as "Type"]
    type_: string,
    [@bs.as "UnsubscribeUrl"]
    unsubscribeUrl: string,
    [@bs.as "TopicArn"]
    topicArn: string,
    [@bs.as "Subject"]
    subject: string,
  };
  [@bs.deriving abstract]
  type record = {
    [@bs.as "EventVersion"]
    eventVersion: string,
    [@bs.as "EventSubscriptionArn"]
    eventSubscriptionArn: string,
    [@bs.as "EventSource"]
    eventSource: string,
    [@bs.as "Sns"]
    sns: message,
  };
  [@bs.deriving abstract]
  type event = {
    [@bs.as "Record"]
    records: array(record),
  };
  type nonrec handler = handler(event);
  type nonrec resultHandler('result) = resultHandler(event, 'result);
};